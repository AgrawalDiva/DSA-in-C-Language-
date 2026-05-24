#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,ch,item,loc;
    int a[200];
    printf("enter the number of element in the list:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter the a[%d] element:",i);
        scanf("%d",&a[i]);
    }
    while(1){
        printf("\n\nMAIN MENU\n\n 1. Insertion\n\n 2. Deletion\n\n 3. Traversal\n\n 4. Exit\n\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            //insertion 
            printf("Enter the item which needs to be added:");
            scanf("%d",&item);
            printf("Enter the location of the item:");
            scanf("%d",&loc);
            loc--;
            for(int i=n-1;i>loc-1;i--){
                a[i+1]=a[i];
            }
            a[loc]=item;
            n++;
            break;
            
            case 2:
            //deletion
            printf("Enter the location of the item needs to be deleted:");
            scanf("%d",&loc);
            loc--;
            for(int i=loc;i<n-1;i++){
                a[i]=a[i+1];
            }
            n--;
            break;
        

            case 3:
            //traversal
            for (int k=0;k<n;k++){
            printf("\n%d",a[k]);}
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Invalid choice");
            break;


        }
    } 
    return 0;
}