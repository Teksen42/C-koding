#include <stdio.h>
#include <math.h>
 
void get_input(double *p1_x, double *p1_y, 
               double *p2_x, double *p2_y, 
               double *p3_x, double *p3_y, 
               double *p4_x, double *p4_y);
double sum_of_sides(double p1_x, double p1_y, 
                    double p2_x, double p2_y,
                    double p3_x, double p3_y, 
                    double p4_x, double p4_y);
double calc_side(double pA_x, double pA_y, 
                 double pB_x, double pB_y);
void print_sum(double sum);
 
int main(void){
 
    double p1_x, p1_y;
    double p2_x, p2_y;
    double p3_x, p3_y;
    double p4_x, p4_y;
    double sum;
 
    get_input(&p1_x, &p1_y, &p2_x, &p2_y, &p3_x, &p3_y, &p4_x, &p4_y);
 
    sum = sum_of_sides(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y);
 
    print_sum(sum);
 
    return 0;
}
 
void get_input(double *p1_x, double *p1_y, double *p2_x, double *p2_y, double *p3_x, double *p3_y, double *p4_x, double *p4_y)
{
     printf("jeg vil nu udregne omkredsen af en firkant for dig\n");
    printf("Tast punkt 1:\n");
    scanf("%lf %lf", p1_x, p1_y);
    printf("Tast punkt 2:\n");
    scanf("%lf %lf", p2_x, p2_y);
    printf("Tast punkt 3:\n");
    scanf("%lf %lf", p3_x, p3_y);
    printf("Tast punkt 4:\n");
    scanf("%lf %lf", p4_x, p4_y);
}
 
double sum_of_sides(double p1_x, double p1_y, double p2_x, double p2_y,
                    double p3_x, double p3_y, double p4_x, double p4_y){
 
    double side12;
    double side23;
    double side34;
    double side41;
 
   
    side12 = calc_side(p1_x, p1_y, p2_x, p2_y);
    side23 = calc_side(p2_x, p2_y, p3_x, p3_y);
    side34 = calc_side(p3_x, p3_y, p4_x, p4_y);
    side41 = calc_side(p4_x, p4_y, p1_x, p1_y);
 
    return side12 + side23 + side34 + side41;
}
 
double calc_side(double pA_x, double pA_y, double pB_x, double pB_y){
    double side;
    double delta_x;
    double delta_y;
    delta_x = pA_x - pB_x;
    delta_y = pA_y - pB_y;
 
    side = sqrt(delta_x*delta_x + delta_y*delta_y);
    return side;
 
}
 
void print_sum(double sum){
    printf("Her er den samlede laengde rundt om firkanten: %lf\n", sum);
}