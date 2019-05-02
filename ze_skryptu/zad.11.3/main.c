#include <stdio.h>
#include <string.h>

struct bip_transistor{
    struct bip_transistor *nextDevice;
    char device[20];
    double beta;
    float maxpower;
    float maxcollectorcurrent;
    double bvceo;
};

void print_devices(struct bip_transistor *tran){

    struct bip_tansistor *temp;

    temp = &tran;
    while(temp){
        static int i = 0;
        printf("%d Device model is %s\t\t",i,temp->device);
        printf("Device Beta is: %.2f\t\t",temp->beta);
        printf("Device maxpower is %.2f\t\t",temp->maxpower);
        printf("Device model is %.2f\t\t",temp->maxcollectorcurrent);
        printf("Device Beta is: %d\n",temp->bvceo);
        temp = temp->nextDevice;
        i++;
    }
}


    while(tran){
        static int i = 0;
        printf("%d Device model is %s\t\t",i,tran->device);
        printf("Device Beta is: %5.2f\t\t",tran->beta);
        printf("Device maxpower is: %5.2f\t\t",tran->maxpower);
        printf("Device maxIc is: %5.2f\t\t",tran->maxcollectorcurrent);
        printf("Device bvco is: %.2f\n",tran->bvceo);
        tran = tran->nextDevice;
        i++;
    }
}

int main() {
/*
    struct bip_transistor tran0;
    struct bip_transistor tran1;
    struct bip_transistor tran2;
    struct bip_transistor tran3;
    struct bip_transistor tran4;
    struct bip_transistor tran5;
    struct bip_transistor tran6;

*/
    struct bip_transistor tran0 = {0,"2N3904",150,0.35,0.2,40};
    struct bip_transistor tran1 = {&tran0,"2N2202",120,0.5,0.3,35};
    struct bip_transistor tran2 = {&tran1, "2N3055",60,120,10,90};
    struct bip_transistor tran3 = {&tran2,"2N1013",95,50,4,110};
    struct bip_transistor tran4 = {&tran3,"MPE106",140,15,1.5,35};
    struct bip_transistor tran5 = {&tran4, "MC1301",80,10,0.9,200};
    struct bip_transistor tran6 = {&tran5, "ECG1201",130,1.3,1.1,55};
    struct bip_transistor *devicesList = &tran6;

    print_devices(devicesList);

    return 0;
}