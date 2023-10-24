int binarySearch(vector<int> &v, int key, int l, int r){
    int n=v.size();
    if(l>=r) return -1;
    int mid=(l+r)/2;
    if(v[mid]==key) return mid;
    else if(v[mid]>key)
    binarySearch(v, key,l, mid-1);
    else
    binarySearch(v, key, mid+1, r);
  
}
