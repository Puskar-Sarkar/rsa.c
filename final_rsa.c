#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int gcd(int a, int b){
if(b==0)
    return a;
return gcd(b, a % b);
}
long long power_mod(long long base, long long exp, long long mod){
    long long res=1;
    while(exp>0){
        if(exp%2==1)
            res=(res*base)%mod;
        exp=exp>>1;
        base=(base*base)%mod;  
    }return res;
}
int main(){
    int p,q,n,phi,e,d;
    long long msg, encrypt, decrypt;
    printf("Enter two prime no (p & q): ");
    scanf("%d %d",&p,&q);
    n=p*q; phi=(p-1)*(q-1);
    for(e=2;e<phi;e++){
        if(gcd(e,phi)==1) break;}
    for(d=1;(d*e)%phi!=1;d++);
    printf("Enter Encrypted msg:");
    scanf("%lld", &msg);
    encrypt=power_mod(msg,e,n);
    decrypt=power_mod(encrypt,d,n);
    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d, n): (%d, %d)\n", d, n);
    printf("Encrypted msg: %lld\n",encrypt);
    printf("Decrypted msg: %lld\n",decrypt);
    return 0;
}
