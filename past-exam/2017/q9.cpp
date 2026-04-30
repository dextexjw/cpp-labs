int palindrome(char *seg, int n)
{
    if (n <= 1)
        return 1;

    if (seg[0] != seg[n - 1])
        return 0;

    return palindrome(seg + 1, n - 2);
}