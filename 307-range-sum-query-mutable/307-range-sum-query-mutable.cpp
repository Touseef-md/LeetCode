class NumArray {
public:
    vector<int> array;
    vector<int> st;
    void updateST(int ss,int se,int index,int diff,int si){
        if(index<ss||se<index)
            return;
        // if(qs<=ss&&qe>=se){
            st[si]+=diff;
            // update()
        // }
        if(ss!=se){
            int mid=ss+(se-ss)/2;
            updateST(ss,mid,index,diff,2*si+1);
            updateST(mid+1,se,index,diff,2*si+2);
        }
    }
    int sRange(int ss,int se,int qs,int qe,int si){
        if(qs<=ss&&qe>=se)
            return st[si];
        if(qe<ss||se<qs)
            return 0;
        int mid=ss+(se-ss)/2;
        return sRange(ss,mid,qs,qe,2*si+1)+sRange(mid+1,se,qs,qe,2*si+2);
    }
    int constructST(int ss,int se,int si){
        if(ss==se){
            return st[si]=array[ss];
            // return ;
        }
        int mid=ss+(se-ss)/2;
        return st[si]=constructST(ss,mid,2*si+1)+constructST(mid+1,se,2*si+2);
        // return 55;
    }
    NumArray(vector<int>& nums) {
        array=nums;
        int l=int(ceil(log2(nums.size())))+1;
        int st_size=(2*(int)(pow(2,l)))-1;
        st.resize(st_size);
        constructST(0,nums.size()-1,0);
    }
    
    void update(int index, int val) {
        updateST(0,array.size()-1,index,val-array[index],0);
        array[index]=val;
    }
    
    int sumRange(int left, int right) {
        // return 0;
        return sRange(0,array.size()-1,left,right,0);
        // if(left>right)
        //     return 0;
        // if(left==right)
        //     return array[left];
        // int mid=left+(right-left)/2;
        // return sumRange(left,mid)+sumRange(mid+1,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */