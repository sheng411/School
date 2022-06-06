int gcd(int m, int n) {
    while(n != 0) { 
        int r = m % n; 
        m = n; 
        n = r;
        printf("m:%d\n",m);
        printf("n:%d\n",n);
        printf("r:%d\n\n",r);
    } 
    return m;
}

int lcm(int m, int n) {
    return m * n / gcd(m, n);
}

void main() { 
    int m, n;
    printf("輸入兩數:");
    scanf("%d %d", &m, &n);
    printf("Gcd:%d\n", gcd(m, n));
    printf("Lcm:%d\n", lcm(m, n));
}