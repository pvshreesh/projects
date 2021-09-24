package Module01;

import java.util.Comparator;

class SortByLength implements Comparator<String>
{
    public int compare(String a, String b)
    {
        return (a.length() - b.length());
    }
}