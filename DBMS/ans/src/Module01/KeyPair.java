package Module01;

class KeyPair
{
    String[] cKeys;
    String R;

    KeyPair(String R, FuncDep[] FDArr)
    {
        this.R = R;
        this.cKeys = Decomposer.getCandidateKeys(R, FDArr);
    }
}
