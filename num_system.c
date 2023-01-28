#include<stdio.h>
#include<math.h>
#include<string.h>
int power(int x,int n){
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return power(x,n/2)*power(x,n/2);
    }
    if(n%2!=0){
        return power(x,n/2)*power(x,n/2)*x;
    }
}



int rev(int num,int revrs,int rem){//reversing a number.
    if(num==0){
        return revrs;
    }
    return rev(num/10,revrs=revrs*10+rem,rem=num%10);
}

int any_num_to_decimal(int num,int system){
    int i=0,dec=0;
    while(num!=0){
        int rem=num%10;
        dec=dec+(rem*(power(system,i)));
        num=num/10;
        i++;
    }
    return dec;
}



int decimal_num_to_any_num(int num,int system){ //convert binery to decimal.
    static int r;
    if(num==0){
        return rev(r,0,0);
    }
    int rem=num%system;
    r=(r*10)+rem;
    return decimal_num_to_any_num(num/system,system);
}

int decimal_num_to_hexadecimal(int num,int system){ //convert binery to decimal.
    if(num==0){
        return 0;
    }
    int rem=num%system;
    int re=decimal_num_to_hexadecimal(num/system,system);
    switch(rem){
        
        default:
        printf("%d",rem);
        break;
        case 15:
        printf("F");
        break;
        case 14:
        printf("E");
        break;
        case 13:
        printf("D");
        break;
        case 12:
        printf("C");
        break;
        case 11:
        printf("B");
        break;
        case 10:
        printf("A");
        break;
    
    }
    return re;
}

void non_deci_to_any_num(float point,int system){
    int i=0;
    float test=0.000000;
    while(i!=18){
        point = point*system;
        if(point ==test){
            break;
        }
        int dec=point;
        printf("%d",dec);
        point=point-dec;
        i++;
    }
}
void non_deci_to_hexadecimal(float point,int system){
    int i=0;
    float test=0.000000;
    while(i!=18){
        point = point*system;
        if(point ==test){
            break;
        }
        int dec=point;
        // printf("%d",dec);
        switch(dec){
        
        default:
        printf("%d",dec);
        break;
        case 15:
        printf("F");
        break;
        case 14:
        printf("E");
        break;
        case 13:
        printf("D");
        break;
        case 12:
        printf("C");
        break;
        case 11:
        printf("B");
        break;
        case 10:
        printf("A");
        break;
    
    }
        point=point-dec;
        i++;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
long long int hexadecimal_to_decimal(char str[],int size){
    long long decimal=0,base=1;
    int i=0;
    for(i=size--;i>=0;i--){
        if(str[i]>='0'&&str[i]<='9'){
            decimal+=(str[i]-48)*base;
            base*=16;
        }
        else if(str[i]>='a'&&str[i]<='f'){
            decimal+=(str[i]-87)*base;
            base*=16;

        }
        else if(str[i]>='A'&&str[i]<='F'){
            decimal+=(str[i]-55)*base;
            base*=16;
        }

    }
    return decimal;
}
double power_re(int i){
    double n;
    n=10*((double)1/pow(16,i));

    return n;
}
double after_point(char str[])
{
    double res=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='A'||str[i]=='a'){
            res+=10*power_re(i+1);
            i++;
        }
        if(str[i]=='B'||str[i]=='b'){
            res+=11*power_re(i+1);
            i++;
        }
        if(str[i]=='c'||str[i]=='C'){
            res+=12*power_re(i+1);
            i++;
        }
        if(str[i]=='D'||str[i]=='d'){
            res+=13*power_re(i+1);
            i++;
        }
        if(str[i]=='e'||str[i]=='E'){
            res+=14*power_re(i+1);
            i++;
        }
        if(str[i]=='F'||str[i]=='f'){
            res+=15*power_re(i+1);
            i++;
        }
        if(str[i]>='f'||str[i]>='F'){
            break;
        }
        if(str[i]=='1'){
            res+=1*power_re(i+1);
        }
        if(str[i]=='2'){
            res+=2*power_re(i+1);
        }
        if(str[i]=='3'){
            res+=3*power_re(i+1);
        }
        if(str[i]=='4'){
            res+=4*power_re(i+1);
        }
        if(str[i]=='5'){
            res+=5*power_re(i+1);
        }
        if(str[i]=='6'){
            res+=6*power_re(i+1);
        }
        if(str[i]=='7'){
            res+=7*power_re(i+1);
        }
        if(str[i]=='8'){
            res+=8*power_re(i+1);
        }
        if(str[i]=='9'){
            res+=9*power_re(i+1);
        }

    }
    
    if(res==0){
        printf("not possible recheck what you entered :  ");
    }
    return res*1000000;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
double fl_bin(int num,double sum,double po,double i,double rem,int system){ //convert float binery to decimal
    if(num==0){
        return sum;
    }
    return fl_bin(num/10,sum=sum+(1/(system*po))*rem,po=power(system,i),i+1,rem=num%10,system);
}


int increased_zeros(int num,int count){  //used for converting intiger value int float
    if(num==0){
        return count;
    }
    return increased_zeros(num/10,count=count*10);
}

int any_num_to_dec(float num,int system){
    float inti_p=num*100000;
    int inti=inti_p;
    int revrs=rev(inti,0,0);
    float final_p=fl_bin(revrs,0,0,0,1,system);
    float final_sem_p=final_p*1000000;
    int final=final_sem_p;
    final=rev(final,0,0);
    final=rev(final,0,0);
    printf(".");
    printf("%d",final);

}

int hexadecimal_converstions(int choice){
    char str[100],strpoint[100],non_point[100];
    int begin=0;
    int helper;
    float helper2;
    printf("enter hexadecimal number :  ");
    fflush(stdin);
    fgets(str,10,stdin);
    int size=strlen(str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='.'){
            begin=i+1;
            break;
        }
    }
    if(begin==0){
        switch (choice){
            case 7:
            printf("%d",hexadecimal_to_decimal(str,size));
            return 0;
            case 8:
            helper=hexadecimal_to_decimal(non_point,size);
            printf("%d",decimal_num_to_any_num(helper,8));
            return 0;
            case 9:
            helper=hexadecimal_to_decimal(non_point,size);
            printf("%d",decimal_num_to_any_num(helper,8));
        }
    }
    for(int i=begin,j=0;str[i]!='\0',j<size;i++,j++){
        strpoint[j]=str[i];
    }
    int c=0;
    for(int i=0;i<begin-1;i++){
        non_point[i]=str[i];
        c++;
    }

    
    switch (choice){
        case 7:
    //hexadecimal to decimal.
        printf("%d",hexadecimal_to_decimal(non_point,c));
        printf(".");
        printf("%0.lf",after_point(strpoint));
        break;
        case 8:
    //hexadecimal to octal.
        helper=hexadecimal_to_decimal(non_point,c);
        printf("%d",decimal_num_to_any_num(helper,8));

        printf(".");
        float helper2=after_point(strpoint)/10000000;
        non_deci_to_any_num(helper2,8);
        break;
        case 9:
    //hexadecimal to binery.
        helper=hexadecimal_to_decimal(non_point,c);
        printf("%d",decimal_num_to_any_num(helper,2));
        printf(".");
        helper2=after_point(strpoint)/10000000;
        non_deci_to_any_num(helper2,2);
        break;
    }


}

int binery_converstions(int choice){
    int helper,r;
    float helper2;
    double num;
    long long decimal=0,base=1;

    printf("enter binary num :  ");
    scanf("%lf",&num);
    double for_intiger_val;
    double for_float_val=modf(num,&for_intiger_val);
    int dec=for_intiger_val;
    float point = for_float_val;
    
    switch (choice){
        case 1:
    //binery to decimal.
        printf("%d",any_num_to_decimal(dec,2));//non float vlaue
        any_num_to_dec(point,2);//float value
        break;
        case 2:
    //binery to octal.
        helper=any_num_to_decimal(dec,2);
        printf("%d",decimal_num_to_any_num(helper,8));

        printf(".");
        helper=any_num_to_dec(point,2);//float values
        r=increased_zeros(helper,1);
        helper2=(float)helper/r;
        non_deci_to_any_num(helper2,8);
        printf("%d",helper2);
        // non_deci_to_any_num(helper2,8);
        break;
        case 3:
    //binery to hexadecimal.
        helper=any_num_to_decimal(dec,2);
        printf("%d",decimal_num_to_hexadecimal(helper,16));

        printf(".");
        helper=any_num_to_dec(point,2);//float values
        r=increased_zeros(helper,1);
        helper2=(float)helper/r;
        non_deci_to_hexadecimal(helper2,16);
        printf("%d",helper2);
        // non_deci_to_any_num(helper2,8);
        break;
    }


}
int decimal_conversion(int choice){
    double num;
    long long decimal=0,base=1;

    printf("enter decimal num :  ");
    scanf("%lf",&num);
    double for_intiger_val;
    double for_float_val=modf(num,&for_intiger_val);
    int dec=for_intiger_val;
    float point = for_float_val;

    switch(choice){
    //decimal to binary
        case 4:
        printf("%d",decimal_num_to_any_num(dec,2));
        printf(".");
        non_deci_to_any_num(point,2);
        break;
    //decimal to octal
        case 5:
        printf("%d",decimal_num_to_any_num(dec,8));
        printf(".");
        non_deci_to_any_num(point,8);
        break;
    //decimal to hexadecimal.
        case 6:
        decimal_num_to_hexadecimal(dec,16);
        printf(".");
        non_deci_to_hexadecimal(point,16);
        break;
    }
    return 0;
}

int octal_conversions(int choice){
    int helper,r;
    float helper2;
    double num;
    long long decimal=0,base=1;

    printf("enter binary num :  ");
    scanf("%lf",&num);
    double for_intiger_val;
    double for_float_val=modf(num,&for_intiger_val);
    int dec=for_intiger_val;
    float point = for_float_val;
    
    switch (choice){
        case 10:
    //octal to decimal.
        printf("%d",any_num_to_decimal(dec,8));//non float vlaue
        any_num_to_dec(point,2);//float value
        break;
        case 11:
    //octal to binery.
        helper=any_num_to_decimal(dec,8);
        printf("%d",decimal_num_to_any_num(helper,2));

        printf(".");
        helper=any_num_to_dec(point,8);//float values
        r=increased_zeros(helper,1);
        helper2=(float)helper/r;
        non_deci_to_any_num(helper2,2);
        printf("%d",helper2);
        // non_deci_to_any_num(helper2,8);
        break;
        case 12:
    //binery to hexadecimal.
        helper=any_num_to_decimal(dec,8);
        decimal_num_to_hexadecimal(helper,16);

        printf(".");
        helper=any_num_to_dec(point,8);//float values
        r=increased_zeros(helper,1);
        helper2=(float)helper/r;
        non_deci_to_hexadecimal(helper2,16);
        non_deci_to_any_num(helper2,8);
        break;
    }
}

int main(){
    double num;
    int choice;
    long long decimal=0,base=1;
    printf("enter 1 for binary to decimal\nenter 2 for binary to octal\nenter to 3 Binary to hexadecimal\n");
    printf("enter 4 for Decimal to Binary\nenter 5 for Decimal to octal\nenter to 6 Decimal to hexadecimal\n");
    printf("enter 7 for hexadecimal to decimal\nenter 8 for hexadecimal to octal\nenter 9 for hexadecimal to binery ");
    printf("enter 10 for octal to decimal\nenter 11 for octal to binary\nenter to 12 octal to hexadecimal :  ");
    scanf("%d",&choice);
    if(choice==1||choice==2||choice==3){
        binery_converstions(choice);
        return 0;
    }

    if(choice==4||choice==5||choice==6){
        decimal_conversion(choice);
        return 0;
    }

    if(choice==7||choice==8||choice==9){
        hexadecimal_converstions(choice);
        return 0;
    }
    if(choice==10||choice==11||choice==12){
        octal_conversions(choice);
        return 0;
    }
    

    printf("enter num :  ");
    scanf("%lf",&num);
    double for_intiger_val;
    double for_float_val=modf(num,&for_intiger_val);
    int dec=for_intiger_val;
    float point = for_float_val;

    switch(choice){
    //decimal to binary
        case 1:
        decimal_num_to_any_num(dec,2);
        printf(".");
        non_deci_to_any_num(point,2);
        break;
    //decimal to octal
        case 3:
        decimal_num_to_any_num(dec,8);
        printf(".");
        non_deci_to_any_num(point,8);
        break;
    //decimal to hexadecimal.
        case 5:
        decimal_num_to_hexadecimal(dec,16);
        printf(".");
        non_deci_to_hexadecimal(point,16);
        break;
    }
    return 0;
}
