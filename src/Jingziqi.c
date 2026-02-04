#include <stdio.h>
/******************井字棋**********************/
int main(void)
{
    system("chcp 65001");

    int chess[3][3] = {{3,3,3},{3,3,3},{3,3,3}};
    int num;//局数
    int i,j;//坐标
    int k;//1 or 0

    printf("Please enter a number: \n");
    printf("格式为坐标加“1”，“0” \n");
    do
    {
        scanf("%d %d %d",&i,&j,&k);
        if (k == 1 || k == 0)//判断是否为1，0
        {
            if (chess[i][j] != 1 && chess[i][j] != 0)//判断位置是否重复
            {
                num++;
                chess[i][j] = k;
                for (int l = 0; l<3;l++)//判断是否有一条直线
                {
                    if (chess[l][0] == chess[l][1] && chess[l][1] == chess[l][2] &&chess[l][0] == k)
                        {printf("\"%d\"player win!",k);
                        return 0;}//检查竖列
                    else if (chess[0][l] == chess[1][l] && chess[1][l] == chess[2][l] && chess[0][l] == k)
                        {printf("\"%d\"player win!",k);
                        return 0;}//检查横列
                    else if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[0][0] == k)
                        {printf("\"%d\"player win!",k);
                        return 0;}//检查正对角线
                    else if (chess[0][2] == chess[1][1] && chess[1][1] == chess[2][0] && chess[1][1] == k)
                        {printf("\"%d\"player win!",k);
                        return 0;}//检查反对角线
                    else
                        continue;
                }
            }
            else
                printf("You should not put this,please try again.\n");
        }
        else
            printf("You should not use this,please try again.\n");
    }while (num <= 9);
    return 0;

}