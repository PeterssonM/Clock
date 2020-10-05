// Maximilian Petersson | 0110050077 | maxpet@kth.se

#include <stdio.h>
#include <stdbool.h>

int update_Time(int t, int s, int m,int h);
int sound_The_Alarm (int pt, int tfa, bool r);

int main()
{
    int present_time, time_for_alarm, s, m, h;
    bool run_time = true;

    printf("Mata in realtiden enligt formatet HHMMSS utan kolon: ");
    scanf("%d", &present_time);

    printf("S�tt alarm enligt samma tidsformat: ");
    scanf("%d", &time_for_alarm);

    while (run_time)
    {
        present_time = update_Time(present_time, s, m, h);
        run_time = sound_The_Alarm(present_time, time_for_alarm, run_time);
    }
    return 0;
}

// Funktionen r�knar upp tiden samt hanterar pretty print av tiden.
int update_Time(int t, int s, int m, int h)
{
    // Konverterar till sekunder, minuter och timmar i den ordningen.
    s = (t % 100);
    m = (t % 10000 - s)/100;
    h = (t % 1000000 - m - s)/10000;

    // pretty print. "...02..." �r ett s�tt att formatera string och betyder att talet som ska printas ut m�ste vara 2 siffrigt. EX. 1 blir 01, 10 blir 10.
    printf("%02d:%02d:%02d\n", h, m, s);

    // L�gger p� 1 sek varje cykel.
    s++;
    // ">=" S�kerst�ller att programmet aldrig blir fast i en evigt uppr�knande loop tillskillnad fr�n ifall det bara hade st�tt "==". Med andra ord en s�kerhetssp�rr.
    if(s >= 60){
        m++;
        s = 0;
    }
    if(m >= 60){
        h++;
        m = 0;
    }
    if (h >= 24){
        h = 0;
    }

    // Konverterar tiden tillbaka till ursprungsformen (dvs ett heltal).
    t = (h*10000)+(m*100)+(s);
    return t;
}

// Funktionen utl�ser alarm
int sound_The_Alarm (int pt, int tfa, bool r){
    if(pt == tfa){
        printf("ALARM!");
        r = false;
    }
    return r;
}
