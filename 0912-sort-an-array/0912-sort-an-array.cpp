class Solution {
public:
    void merge(vector<int> &arr, int s, int e){


    int mid =  s + (e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy value;
    int mainArray = s;

    for(int i=0; i<len1; i++){
        first[i] = arr[mainArray++];
    }

    mainArray = mid+1;

    for(int i=0; i<len2; i++){
        second[i] = arr[mainArray++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArray = s;
    
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArray++] = first[index1++];
        }
        else{
            arr[mainArray++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[mainArray++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArray++] = second[index2++];
    }



    
}
void mergeSort(vector<int> &arr, int s, int e){
     
    if(s >= e){
        return;
    }
    int mid =  s + (e-s)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);

}
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};