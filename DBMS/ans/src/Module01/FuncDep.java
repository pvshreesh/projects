package Module01;

class FuncDep
{
    String X, Y;
    FuncDep(String X, String Y)
    {
        this.X = X;
        this.Y = Y;
    }

    public boolean equals(FuncDep fd)
    {
        boolean flag1 = this.X.equals(fd.X);
        boolean flag2 = this.Y.equals(fd.Y);
        return (flag1 && flag2);
    }

    private boolean check2NF(String[] cKeys)
    {
        String primeAttributes = "";
        for(String k : cKeys)
            primeAttributes = Decomposer.appendToStr(primeAttributes, k);

        if(!Decomposer.isSubset(primeAttributes, Y))
        {
            boolean flag = false;
            for(String key : cKeys)
            {
                flag = (Decomposer.sortString(key).equals(Decomposer.sortString(X))
                        || !Decomposer.isSubset(key, X));
                if(flag == true)
                    return true;
            }
            if(flag == false)
                return false;
        }
        return true;
    }

    private boolean check3NF(String[] cKeys)
    {
        if(this.check2NF(cKeys) == false) return false;

        String primeAttributes = "";
        for(String k : cKeys)
            primeAttributes = Decomposer.appendToStr(primeAttributes, k);

        for(String key : cKeys)
        {
            if(Decomposer.isSubset(X, key))
                return true;
            else if(Decomposer.isSubset(primeAttributes, Y))
                return true;
        }
        return false;
    }

    private boolean checkBCNF(String[] cKeys)
    {
        if(this.check3NF(cKeys) == false) return false;

        String primeAttributes = "";
        for(String k : cKeys)
            primeAttributes = Decomposer.appendToStr(primeAttributes, k);

        for(String key : cKeys)
        {
            if(Decomposer.isSubset(X, key))
                return true;
        }

        return false;
    }

    public int getNF(String[] cKeys)
    {
        if(this.checkBCNF(cKeys)) return 4;
        else if(this.check3NF(cKeys)) return 3;
        else if(this.check2NF(cKeys)) return 2;
        return 1;
    }
}