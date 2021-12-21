#include<bits/stdc++.h>
using namespace std;

char str[100];

bool isother(){
    for(int i=0;str[i];i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')){
            continue;
        }
        else{
            return 1;
        }
    }
    return 0;
}

// 0-9 a
bool isAllDigit(){
    for(int i=0; str[i];i++){
        if(str[i]<'0'||str[i]>'9') return 0;
    }
    return 1;
}

int main(){

    cin>>str;

    int ln = strlen(str);

    if(isother()){
        puts("Undefined");
    }
    else if((str[0]>='i'&&str[0]<='n')||(str[0]>='I'&&str[0]<='N')){
        puts("Integer Variable");
    }
    else if(isAllDigit()&&(str[0]>='1'&&str[0]<='9')&&ln<=4){
        puts("Short Integer");
    }
    else if(isAllDigit()&&(str[0]>='1'&&str[0]<='9')){
        puts("Long Integer");
    }
    else{
        puts("Undefined");
    }

    return 0;
}