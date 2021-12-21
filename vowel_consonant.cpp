#include<stdio.h>

char str[100];

int is_digit(char ch){
    if(ch>='0'&&ch<='9') return 1;
    return 0;
}

int is_char(char ch){
    if(ch>='A'&&ch<='Z') return 1;
    if(ch>='a'&&ch<='z') return 1;
    return 0;
}

int is_vowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return 1;
    return 0;
}

int mr[200];

void solve(){

    int cnt=0,vow=0,cons=0,vow1=0,cons1=0, others = 0,i,j,k,x,y;
    char vw[1000],cns[1000];
    for(i=0;str[i];i++){
        if(is_vowel(str[i])){
           vow++;
            if(!mr[(int)str[i]])
                vw[vow1++] = str[i];             
           //printf("%c\n",vw[vow-1]);
        }
        else if(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z'){
            cons++;
            if(!mr[(int)str[i]])
                cns[cons1++] = str[i];
        }
        mr[(int)str[i]] = 1;
    }
    printf("\nNumbers of VOWELS : %d\n",vow);
    printf("Numbers of CONSONANTS : %d\n",cons);
    printf("\nVowels : ");
    for(i=0;i<vow1;i++){
        printf("%c ",vw[i]);
    }
    printf("\nConsonants : ");
    for(i=0;i<cons1;i++){
        printf("%c ",cns[i]);
    }
}

void separate(){
    int i,j,k,l,m,n,in1=0,in2=0;
    char vw[1000],cns[1000];

    for(i=0;str[i];i++){
        if(is_vowel(str[i])){
            while(str[i]!=' '&&str[i]!='\0'){
                vw[in1++] = str[i];
                i++;
            }
            //printf("I: %d\n", i);
            //i--;
            vw[in1++]  = ' ';
        }
        else if(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z'){
            while(str[i]!=' '&&str[i]!='\0'){
                cns[in2++] = str[i++];
            }
            //i--;
            cns[in2++]  = ' ';
        }
    }
    vw[in1] = '\0';
    cns[in2] = '\0';
    printf("\n\nWords started with vowel : %s\n",vw);
    printf("Words started with consonant : %s\n",cns);
}


/// Md. Tareq Zaman, Part-3, 2019 ami am khai

int main(){

    int i,j,k,l,m,n;

    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf(" %[^\n]",str);

    solve();
    separate();
    return 0;
}
