void flipArr (double arr[], int n);

int main(void){
    double arr[5]={1,2,3,4,5};
    flipArr(arr, 5);
    return 0;
}
void flipArr (double arr[], int n){
    static int min=0;
    int max=(n-1);
    if(max==min){
        return;
    }
    else{
        double i= arr[min];
        arr[min]=arr[max];
        arr[max]= i;
        min++;
        return flipArr(arr, n-1);
    }
}