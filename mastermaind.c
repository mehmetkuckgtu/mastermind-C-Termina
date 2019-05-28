
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>

int main ()
{

/*
     srand(time(0));
    int Seed = rand();   // bu kýsými ben  oynamak için oluþturdum.
    int outone=rand()%8;   // çýkýþa random sayýlar atamaktadýr.
    int outtwo=rand()%8;
    int outthree=rand()%8;
    int outfour=rand()%8;
    srand(Seed);
    int outs[4]={outone,outtwo,outthree,outfour};*/
    int outs[4]={3,2,2,2};  //ödevde örnek olarak verilen output deðerleri.
    int inputs[4];
    char inputc[10];
    int hak=0;
    int redCount=0;

    int i=0;

    char continueone='y';


    printf("reselemek icin r ye basiniz\n");


    while(continueone == 'y')// oyuncu tekrar oynamasý için þeçenek sunulyor.
    {

        for (i=0;i<4;++i)
        {

            printf("%d",outs[i]);
        }

        do//tahmin deðerleri girilecek.
        {
            sprintf(inputc,"-1"); //kodda inputlari sifirlamak icin kullanıldı.
            for(i=0; i<4; ++i)
            {
                inputs[i]=-1;
            }

            printf("\n predict first colors\n");
            scanf ("%s",inputc);
            sscanf(inputc, "%d", &inputs[0]); //string  int dönüştürme
            if(inputc[0]=='r')
                break;
            printf("predict second colors\n");
            scanf ("%s",inputc);
            sscanf(inputc, "%d", &inputs[1]);//string  int dönüştürme
            printf("predict third colors\n");
            scanf ("%s",inputc);
            sscanf(inputc, "%d", &inputs[2]);//string  int dönüştürme
            printf("predict fourth colors\n");
            scanf ("%s",inputc);
            sscanf(inputc, "%d", &inputs[3]);//string  int dönüştürme



            if(checkInput(inputs))//check edilip ,fonksiyonlarýn çagirildigi ve terminale yazilan yer.
            {
                int whiteCount=0; int whiteFix=0;
                  redCount=0; int redFix=0;
                /////////////////////////////////////
                int index_rcOuts[4] ={99,99,99,99};
                int index_rcInputs[4] ={99,99,99,99};
                int index_wcOuts[4] = {99,99,99,99};
                int index_wcInputs[4] = {99,99,99,99};
                int e;
                int r;



                for(e=0;e<4;++e)
                {
                    for(r=0;r<4;++r)
                    {
                        if(inputs[r]==outs[e])
                        {
                            if(e==r)
                            {
                                //renk doğru sıra doğru
                                ++redCount;
                                ++redFix;
                                index_rcOuts[redFix-1]= e;
                                index_rcInputs[redFix-1]= r;
                                if(isIncluded(e,index_wcOuts) || isIncluded(r,index_wcInputs))
                                {
                                    --whiteCount;
                                    index_wcOuts[e]=99;
                                    index_wcInputs[r]=99;
                                }
                                //else{}

                            }
                            else
                            {
                                //renk doğru sıra yanlış
                                if(!(isIncluded(e,index_rcOuts) || isIncluded(r,index_rcInputs)))
                                {


                                //else

                                    if(!(isIncluded(e,index_wcOuts) || isIncluded(r,index_wcInputs)))
                                    {



                                    //else()

                                        ++whiteCount;
                                        ++whiteFix;
                                        index_wcOuts[whiteFix-1]=e;
                                        index_wcInputs[whiteFix-1]=r;
                                    }


                                }

                        }
                        //else{
                        }

                    }
                }
                    /////////////////////////////////////

                    printf("----> RED: %d --- WHITE: %d\n",redCount,whiteCount);
                    hak++;
                }
                else
                    printf("wrong answer,try again\n");

            }while((redCount!=4) && (hak!=10)); //döngüden çikilan yer. maksimum 10 hakkin var ve






        if(redCount == 4)
            printf("BRAVOOOO\n");
        else
            printf("try again\n");

        printf("Do you want to continue? \n");
        scanf("%c",&continueone);
        scanf("%c",&continueone);
        }
    }

int checkInput(int inputs[])//kullanýcýnýn giriŞ deðerlerini yanlýþ girmesi engelleniyor.
{
    int i=0;
    for(i=0 ; i<4 ; ++i)
    {
        if(inputs[i]<0 || inputs[i]>7)
            return 0;
    }
    return 1;
}

int isIncluded(int number, int array[])
{
    int i;
    int value = 0;
    for(i=0; i<4;i++)
    {
        if(number == array[i])
        {
            value = 1;
            break;
        }
        //else {}
    }
    return value;
}


void checkRedandWhite(int outs[], int inputs[],int whiteCount, int redCount)
{
    whiteCount=0; redCount = 0;
    int index_rcOuts[4] ={99,99,99,99};
    int index_rcInputs[4] ={99,99,99,99};
    int index_wcOuts[4] = {99,99,99,99};
    int index_wcInputs[4] = {99,99,99,99};
    int e;
    int r;



    for(e=0;e<4;++e)
    {
        for(r=0;r<4;++r)
        {
            if(inputs[r]==outs[e])
            {
                if(e==r)
                {
                    ++redCount;
                    index_rcOuts[redCount-1]= e;
                    index_rcInputs[redCount-1]= r;
                    if(isIncluded(e,index_wcOuts) || isIncluded(r,index_wcInputs))
                    {
                        --whiteCount;
                    }

                }
                else
                {
                    if(isIncluded(e,index_rcOuts) || isIncluded(r,index_rcInputs))
                    {

                    }
                    else
                    {
                        if(isIncluded(e,index_wcOuts) || isIncluded(r,index_wcInputs)){}
                        else
                        {
                            ++whiteCount;
                            index_wcOuts[whiteCount-1]=e;
                            index_wcInputs[whiteCount-1]=r;
                        }

                    }
                }

            }
            else
            {

            }

        }
    }
}
