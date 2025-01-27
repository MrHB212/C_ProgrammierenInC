#include <stdio.h>

//Formatierung
//Funktionen erstellen

int main (){
    int n;
    int a = 1;
    //Eingabe
    scanf("%d", &n);
    
    //Falls Eingabe von n negativ, dann * -1
    if(n<0){
        n *= -1;
    }
    //Deklariere Array der nächsten Eingabe
    int eingabe[n+1];

    //Eingabe für jeden Index im Array
    for(int i = 0; i != n; ++i){
        scanf("%d", &eingabe[i]);      
    }

    //Ist Array aufsteigend ?
    for (int i = 0; i < n; i++){
        while (a == 1 && i < n - 1) {
                if (eingabe[i] > eingabe[i+1]){
                a = 0; 
                }
            i++;
                
        }
    }

    //Ausgabe Text
    if(a==1){
        printf("aufsteigend");
    }else{
        printf("nicht aufsteigend\n");
    }

    //Ausgabe Sortierung
    if (a==0){
    int i, j;
    int x, y;
    for (i=1; i<n; i++){ 
        for (j=0; j<n-i; j++){
        x = eingabe[j]; y = eingabe[j+1];
        if(x > y){
            eingabe[j] = y; 
            eingabe[j+1] = x;
        }
        }
    }

    //Array Ausgabe
    for(int i = 0; i<n; ++i){
        printf("%d ", eingabe[i]);
    }

}

    return 0;

}





    