//Nathan Reymer
//0797359

#include "linked.c"

int main(int argc, char**argv) {
    char* input=calloc(80,sizeof(char)); //Should be more than enough.
    struct node *AVL, *F;
    AVL = malloc(sizeof(struct node) );
    F=malloc(sizeof(struct node));
    int choice,iInput;
    
    printf("\n************************** \n");
    printf("       Nathan Reymer \n         0797369 \n"); //Well Hey thats me
    printf("************************** \n");


    while(choice!=7)    //Start the loop
    {
        printf("\nEnter a number: \n");
        printf("1. Initialization \n");
        printf("2. Find \n");
        printf("3. Insert \n");
        printf("4. Remove \n");
        printf("5. Check Height and Size \n");
        printf("6. Find All (above a given frequency) \n");
        printf("7. Exit. \n");
        printf("avl/> ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Filename: ");
            scanf("%s",input);
            AVL=readFile(input,AVL);
            break;
            case 2:
            printf("Find key: ");
            scanf("%s",input);
            F=findKey(input, AVL);
            if(F==NULL)
            printf("no_such_key\n"); //Ugly phrase, but okay!
            else
                printf("Key: %s, Frequency: %d\n",F->key,F->freq);
            break;
            case 3:
            printf("Insert key: ");
            scanf("%s",input);
            F=findKey(input, AVL);  //insert key or Bump up key freq
            if(F==NULL)
            {
                AVL=insert(1,input,AVL);
            }
            else
            {
                F->freq++;
            }
            F=findKey(input, AVL);
            printf("Key: %s, Frequency: %d\n",F->key,F->freq);
            break;
            case 4:
            printf("Remove key: "); //Same thing as above but reverse
            scanf("%s",input);
            F=findKey(input, AVL);
            if(F==NULL)
            {
                printf("no_such_key\n");
            }
            else if(F->freq>1)
            {
                F->freq--;
            }
            else
            {
                AVL=deleteNode(AVL,input);
            }
            break;
            case 5:
            printf("Height %d Size: ",height(AVL));//Size?
            break;
            case 6:
            printf("Frequency: ");
            scanf("%s",input);
            iInput=atoi(input);
            findFreq(iInput,AVL);
            break;
            case 7:
            break;
            default:
            printf("Not an option \n"); //Please dont loop?
        }

    }
}
