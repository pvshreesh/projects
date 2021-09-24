package Module01;

import java.util.*;

class Decomposer
{
    static String appendToStr(String R, String x)
    {
        for(char c : x.toCharArray())
        {
            if(!R.contains(String.valueOf(c)))
                R += String.valueOf(c);
        }
        return R;
    }

    static boolean isSubset(String sup, String sub)
    {
        for(char c : sub.toCharArray())
        {
            if(!sup.contains(String.valueOf(c)))
                return false;
        }
        return true;
    }

    static String sortString(String x)
    {
        char[] Xchars = x.toCharArray();
        Arrays.sort(Xchars);
        String XSorted = new String(Xchars);
        return XSorted;
    }

    static String generateClosure(String x, FuncDep[] FuncDep)
    {
        String Xplus = x;
        String oldX = "";
        while(oldX != Xplus)
        {
            oldX = Xplus;
            for(int j = 0; j < FuncDep.length; j++)
            {
                if(isSubset(Xplus, FuncDep[j].X))
                    Xplus = appendToStr(Xplus, FuncDep[j].Y);
            }
        }
        return Xplus;
    }

    static LinkedHashMap<String, String> getClosures(FuncDep[] FDArr)
    {
        LinkedHashMap<String, String> answer = new LinkedHashMap<String, String>();
        String R = "";
        for(FuncDep fd : FDArr)
            R = appendToStr(R, fd.X + fd.Y);

        R = sortString(R);
        for(int i = 1; i < Math.pow(2, R.length()); i++)
        {
            String k = "";
            for(int j = 0; j < R.length(); j++)
            {
                if(((i >> j) & 1) == 1)
                    k += String.valueOf(R.charAt(j));
            }
            String c1 = generateClosure(k, FDArr);
            answer.put(k, sortString(c1));
        }
        return answer;
    }
    static FuncDep[] convertToCanonicalForm(FuncDep[] FDArr)
    {
        ArrayList<FuncDep> fdal = new ArrayList<FuncDep>(Arrays.asList(FDArr));
        for(int i = 0; i < fdal.size(); i++)
        {
            FuncDep fd = fdal.get(i);
            if(fd.Y.length() != 1)
            {
                ArrayList<FuncDep> canonical = new ArrayList<FuncDep>();
                for(char c : fd.Y.toCharArray())
                    canonical.add(new FuncDep(fd.X, String.valueOf(c)));

                fdal.remove(i);
                fdal.addAll(i, canonical);
            }
        }
        FuncDep[] canonicalFDArr = new FuncDep[fdal.size()];
        canonicalFDArr = fdal.toArray(canonicalFDArr);
        return canonicalFDArr;
    }

    static FuncDep[] getMinimalCover(FuncDep[] FDArr1)
    {
        FuncDep[] FDArr2 = convertToCanonicalForm(FDArr1);
        ArrayList<FuncDep> FDArr = new ArrayList<FuncDep>(Arrays.asList(FDArr2));
        LinkedHashMap<String, String> F = getClosures(FDArr1);

        for(int i = 0; i < FDArr.size(); i++)
        {
            FuncDep fd = FDArr.get(i);
            ArrayList<FuncDep> temp = new ArrayList<FuncDep>(FDArr);

            if(fd.X.length() == 1)
                continue;

            for(char c : fd.X.toCharArray())
            {
                LinkedHashMap<String, String> G;
                temp.remove(fd);
                String tempX = fd.X.replace(String.valueOf(c), "");
                FuncDep fdTemp = new FuncDep(tempX, fd.Y);
                if(!temp.contains(fdTemp))
                    temp.add(fdTemp);

                FuncDep[] tempFDArr = new FuncDep[temp.size()];
                tempFDArr = temp.toArray(tempFDArr);
                G = getClosures(tempFDArr);

                if(G.equals(F))
                {
                    FDArr.remove(i);
                    FDArr.add(i, fdTemp);
                }
            }
        }

        ArrayList<FuncDep> init = new ArrayList<FuncDep>(FDArr);
        for(FuncDep fd : init)
        {
            LinkedHashMap<String, String> G;
            ArrayList<FuncDep> temp = new ArrayList<FuncDep>(FDArr);

            temp.remove(fd);
            FuncDep[] tempFDArr = new FuncDep[temp.size()];
            tempFDArr = temp.toArray(tempFDArr);
            G = getClosures(tempFDArr);

            if(G.equals(F))
                FDArr.remove(fd);
        }

        FuncDep[] finalAnswer = new FuncDep[FDArr.size()];
        finalAnswer = FDArr.toArray(finalAnswer);
        return finalAnswer;
    }


    static String[] getCandidateKeys(String R, FuncDep[] FuncDep)
    {
        String RSorted = sortString(R);
        ArrayList<String> keys = new ArrayList<String>();

        int n = R.length();
        for(int i = 1; i < Math.pow(2, n); i++)
        {
            String key = "";
            for(int j = 0; j < n; j++)
            {
                if(((i >> j) & 1) == 1)
                    key += String.valueOf(R.charAt(j));
            }

            String XSorted = sortString(generateClosure(key, FuncDep));
            if(RSorted.equals(XSorted))
                keys.add(key);
        }

        Collections.sort(keys, new SortByLength());
        int s = keys.size();
        for(int i = s-1; i >= 0; i--)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(isSubset(keys.get(i), keys.get(j)))
                {
                    keys.remove(i);
                    break;
                }
            }
        }

        String[] cKeys = new String[keys.size()];
        cKeys = keys.toArray(cKeys);
        return cKeys;

    }

    static int getNFVal(FuncDep[] FDArr, String[] cKeys)
    {
        int minNF = 4;
        for(FuncDep fd : FDArr)
        {
            if(minNF > fd.getNF(cKeys))
                minNF = fd.getNF(cKeys);
        }
        return minNF;
    }
    static String getNFString(FuncDep[] FDArr, String[] cKeys)
    {
        int val = getNFVal(FDArr, cKeys);
        if(val == 4)
            return "BCNF";
        else
            return val+"NF";
    }

    static FuncDep[] getRelevantFDs(String R, FuncDep[] FDArr)
    {
        ArrayList<FuncDep> relevantFDs = new ArrayList<FuncDep>();
        for(FuncDep fd : FDArr)
        {
            String mix = fd.X + fd.Y;
            if(isSubset(R, mix))
                relevantFDs.add(fd);
        }

        FuncDep[] rFDs = new FuncDep[relevantFDs.size()];
        rFDs = relevantFDs.toArray(rFDs);
        return rFDs;
    }

    static ArrayList<KeyPair> convertTo2NF(KeyPair rel, FuncDep[] FDArr)
    {
        String R = rel.R;
        String[] cKeys = rel.cKeys;
        HashSet<String> decompositions = new HashSet<String>();
        HashSet<String> decompositions2 = new HashSet<String>();
        for(FuncDep fd : FDArr)
        {
            if(fd.getNF(cKeys) == 1)
            {
                String k = sortString(fd.Y);
                String k1=sortString(fd.X);
                String dec = generateClosure(k, FDArr);
                //  dec+=k1;
                decompositions.add(dec+k1);
                decompositions2.add(dec);
            }
        }
        String done = "";
        Iterator<String> dit = decompositions2.iterator();
        while(dit.hasNext())
            done = appendToStr(done, dit.next());

        String extra = "";
        for(FuncDep fd : FDArr)
        {
            String mix = fd.X + fd.Y;
            for(int i=0;i<mix.length();i++)
            {
                String temp=String.valueOf(mix.charAt(i));
                if(!isSubset(done,temp))
                    extra=appendToStr(extra,temp);
            }
        }
        if(!extra.isEmpty())
            decompositions.add(extra);

        ArrayList<KeyPair> finalDecs = new ArrayList<KeyPair>();
        dit = decompositions.iterator();
        while(dit.hasNext())
        {
            String myR = dit.next();
            FuncDep[] myFDArr = getRelevantFDs(myR, FDArr);
            finalDecs.add(new KeyPair(myR, myFDArr));
        }
        return finalDecs;
    }

    static ArrayList<KeyPair> convertTo3NF(KeyPair rel, FuncDep[] FDArr1)
    {
        FuncDep[] FDArr = getMinimalCover(FDArr1);
        ArrayList<String> decs = new ArrayList<String>();
        // Removes the Canonical Forms after getting Minimal Cover
        for(FuncDep fd1 : FDArr)
        {
            String R = fd1.X;
            for(FuncDep fd2 : FDArr)
            {
                if(fd2.X.equals(fd1.X))
                    R = appendToStr(R, fd2.Y);
            }
            if(!decs.contains(R))
                decs.add(R);
        }

        // Sorts the output string
        for(int i = 0; i < decs.size(); i++)
        {
            String r1 = decs.get(i);
            r1 = sortString(r1);
            decs.remove(i);
            decs.add(i, r1);
        }

        // Removes duplicates from the Array
        ArrayList<String> decsCopy = new ArrayList<String>(decs);
        for(String r1 : decsCopy)
        {
            for(String r2 : decsCopy)
            {
                if(!r1.equals(r2) && r2.contains(r1) && decsCopy.contains(r1))
                    decs.remove(r1);
            }
        }

        ArrayList<KeyPair> decompositions = new ArrayList<KeyPair>();
        for(String r : decs)
        {
            String r1 = sortString(r);
            decompositions.add(new KeyPair(r1, getRelevantFDs(r1, FDArr)));
        }
        return decompositions;
    }

    static ArrayList<KeyPair> convertToBCNF(KeyPair rel, FuncDep[] FDArr)
    {
        String[] cKeys = rel.cKeys;
        String R = rel.R;

        ArrayList<KeyPair> relations = new ArrayList<KeyPair>();
        KeyPair kr1=new KeyPair(R,getRelevantFDs(R,FDArr));
        for(FuncDep fd : FDArr)
        {
            if(fd.getNF(cKeys) == 3)
            {
                String r1 = R;
                for(char c : fd.Y.toCharArray())
                {
                    if(r1.contains(String.valueOf(c)))
                        r1 = r1.replace(String.valueOf(c), "");
                }
                String r2 = appendToStr(fd.X, fd.Y);
                r1 = sortString(r1);
                r2 = sortString(r2);
                kr1 = new KeyPair(r1, getRelevantFDs(r1, FDArr));
                KeyPair kr2 = new KeyPair(r2, getRelevantFDs(r2, FDArr));
                // relations.add(kr1);
                R=kr1.R;
                relations.add(kr2);
            }
        }
        relations.add(kr1);

        return relations;
    }
    static String finans="";
    static int printHelper(ArrayList<KeyPair> d, FuncDep[] FDArr)
    {

        for(KeyPair r : d)
        {
            finans+=("Relation: " + r.R + "  || CK(s): "+"\n");
            for(int i = 0; i < r.cKeys.length-1; i++)
                finans+=(r.cKeys[i] + ", "+"\n");
            finans+=(r.cKeys[r.cKeys.length-1]+"\n");
        }
        System.out.println(finans);

        int minLevel = 4;
        for(KeyPair r : d)
        {
            int level = getNFVal(getRelevantFDs(r.R, FDArr), r.cKeys);
            if(level < minLevel)
                minLevel = level;
        }
        return minLevel;


    }

    static void printFinalAnswer(KeyPair KR, FuncDep[] FDArr)
    {
        int initLevel = getNFVal(FDArr, KR.cKeys);
        int level = initLevel;
        finans="";
        switch(level)
        {
            case 1:
                finans+=("1 NF to 2 NF" +"\n" + "----------------------------------------\n");
                level = printHelper(convertTo2NF(KR, FDArr), FDArr);
                break;
            case 2:
                finans+=("2 NF to 3 NF" +"\n" + "----------------------------------------\n");
                level = printHelper(convertTo3NF(KR, FDArr), FDArr);
                break;
            case 3:
                if(level != initLevel)
                {
                    ArrayList<KeyPair> rels = convertTo3NF(KR, FDArr);
                    ArrayList<KeyPair> copy = new ArrayList<KeyPair>(rels);
                    for(int i = 0; i < copy.size(); i++)
                    {
                        KeyPair kr = copy.get(i);
                        FuncDep[] relevantFDs = getRelevantFDs(kr.R, FDArr);
                        if(getNFVal(relevantFDs, kr.cKeys) == 3)
                        {
                            rels.remove(kr);
                            rels.addAll(i, convertToBCNF(kr, relevantFDs));
                        }
                    }
                    finans+=("3 NF to BCNF" +"\n" + "----------------------------------------\n");
                    level = printHelper(rels, FDArr);
                }
                else
                {
                    finans+=("3 NF to BCNF" +"\n" + "----------------------------------------\n");
                    level = printHelper(convertToBCNF(KR, FDArr), FDArr);
                }
                break;
            default:
                System.out.println("ERROR in RelUtil.printFinalAnswer()");
        }
        System.out.println("------------------------------" +
                "-------------------------");
        if(level == 4)
        {
            finans+=("Relation(s) already in BCNF");
            System.out.println("------------------------------" +
                    "-------------------------");
            return;
        }
        else
            System.out.println("Relation(s) are in " + level + "NF");


        // if(level != 4)
        //   System.out.println("--------------------------------" +
        //                                             "-----------------------");
    }
}
