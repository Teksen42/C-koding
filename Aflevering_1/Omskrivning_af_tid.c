#include <stdio.h>

#define sekunder_pr_minut 60
#define minutter_pr_time  60
#define timer_pr_dag      24
#define dage_pr_uge       7

int main(void){
    // Vi kalder variablen 'resterende_tid', da indholdet ændrer sig løbende
    int resterende_tid; 
    int uger, dage, timer, minutter, sekunder;

    printf("Indtast antal sekunder: \n");
    scanf("%d", &resterende_tid);

    // 1. Find sekunder (resten ved division med 60)
    sekunder = resterende_tid % sekunder_pr_minut;
    
    // 2. Omregn resten til minutter (heltalsdivision)
    // Nu betyder 'resterende_tid' pludselig minutter!
    resterende_tid = resterende_tid / sekunder_pr_minut;

    // 3. Find minutter (resten af de tilbageværende minutter)
    minutter = resterende_tid % minutter_pr_time;

    // 4. Omregn resten til timer
    // Nu betyder 'resterende_tid' pludselig timer!
    resterende_tid = resterende_tid / minutter_pr_time;

    // 5. Find timer
    timer = resterende_tid % timer_pr_dag;

    // 6. Omregn resten til dage
    // Nu betyder 'resterende_tid' pludselig dage!
    resterende_tid = resterende_tid / timer_pr_dag;

    // 7. Find dage
    dage = resterende_tid % dage_pr_uge;

    // 8. Resten er nu antal uger
    uger = resterende_tid / dage_pr_uge;

    printf("%d uger, %d dage, %d timer, %d minutter, %d sekunder\n", 
           uger, dage, timer, minutter, sekunder);

    return 0;
}