class Solution {
    public int romanToInt(String s) {
        
        
        
        int l = s.length(), i, N = 0;
        char c;
        int n[] = new int[l+1];
        for (i = 0; i < l; i++)
        {
            c = s.charAt(i);
            if (c == 'I')
                n[i] = 1;
            else if (c == 'V')
                n[i] = 5;
            else if (c == 'X')
                n[i] = 10;
            else if (c == 'L')
                n[i] = 50;
            else if (c == 'C')
                n[i] = 100;
            else if (c == 'D')
                n[i] = 500;
            else
                n[i] = 1000;
        }
        for (i = 0; i < l; i++)
        {
            if (n[i] < n[i+1])
            {
                N+= n[i+1] - n[i];
                i++;
            }
            else
                N+= n[i];
        }
        return N;
        
        
        
    }
}