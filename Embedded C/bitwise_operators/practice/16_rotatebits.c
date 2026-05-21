#include<stdio.h>
void rotateright(int n,int d);
void rotateleft(int n,int d)
{
    int left;
    left=(n>>d)|(n<<(n-d));
    printf("%d",left);
}
int main()
    {
        int num,d;
        printf("enter number and bits to rotate");
        scanf("%d %d",&num,&d);
        rotateleft(num,d);
        rotateright(num,d);
    }
    void rotateright(int n,int d)
    {
        int right;
        right=(n<<d)|(n>>(n-d));
        printf("%d",right);
    }
