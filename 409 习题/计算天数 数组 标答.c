# include <stdio.h>
/* 计算某个日期对应该年的第几天 */
int day_of_year(int year, int month, int day)
{
    int k, leap;
    int tab[2][13] = {					/* 数组初始化，将每月的天数赋给数组 */
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
    };

    /* 判断闰年，当year是闰年时，leap=1；当year是非闰年时，leap=0 */
    leap = (year % 4 == 0 && year%100!=0 || year%400==0); 

    /* 计算天数 */
    for(k = 1; k < month; k++){ 
       day = day + tab[leap][k];
    } 

    return day; 
}    

int main(void) 
{
	int day, month, year;
	
	printf("Enter year, month, day: "); 
    scanf("%d%d%d", &year, &month, &day);
    printf("%d\n", day_of_year(year, month, day));
    
    return 0;
}

