#ifndef _RMQ_
  #define _RMQ_
  #include <bits/stdc++.h>

  class rmq{

    private:

      int n_blocks;//number of blocks
      int sz_block;//size of each block
      int * trav; //cartesian tree traversal
      int* depths;// depths of nodes
      int* first_occ;//first occurrences of the elements in the tree
      int*** rmq_mask;//rmq of all possible 1-difference-blocks of size log(n)/2
      int** rmq_blocks;//rmq over all blocks of trav
      int* block_mask;//conversion from block to mask
      int trav_sz;//size of tree traversal
      int cartesian_build(int* arr, int n, std::pair<int,int>* t){ //create cartesian tree from array
          for(int i=0;i<n;i++)t[i]=std::make_pair(-1,-1);
          std::stack<int> s;
          for(int i=0;i<n;i++){
            int last=-1;
            while(!s.empty()&&arr[s.top()]>=arr[i]){
              last=s.top();
              s.pop();
            }
            if(!s.empty())t[s.top()].second=i;
            if(last>=0)t[i].first=last;
            s.push(i);
          }
          while(s.size()>1)s.pop();
          return s.top();
      }
      void euler_tour(std::pair<int,int> *g, int n, int &sz, int depth){//build cartesian tree traversal
        first_occ[n]=sz;
        trav[sz++]=n;
        depths[n]=depth;
        if(g[n].first>=0){
        euler_tour(g,g[n].first,sz, depth+1);
        trav[sz++]=n;
      }if(g[n].second>=0){
        euler_tour(g,g[n].second,sz, depth+1);
        trav[sz++]=n;
      }
      }
      void trav_build(int* arr, int n){//convert array to trav
        std::pair<int,int>* tree=new std::pair<int,int>[n];
        int root=cartesian_build(arr,n,tree);
        trav_sz=0;
        euler_tour(tree,root,trav_sz,0);
        delete [] tree;
      }

    public:

      rmq(int* a, int n){
        depths=(int*)malloc(n*sizeof(int));
        first_occ=(int*)malloc(n*sizeof(int));
        trav=(int*)malloc((2*n-1)*sizeof(int));
        trav_build(a,n);
        n=2*n-1;
        assert(trav_sz<=n);
         sz_block=std::__lg(n)/2+1;
         n_blocks=(n+sz_block-1)/sz_block;
        rmq_mask=(int***)malloc((1<<(sz_block-1))*sizeof(int**));
        for(int i=0;i<(1<<(sz_block-1));i++)rmq_mask[i]=(int**)malloc(sz_block*sizeof(int*));
        for(int i=0;i<(1<<(sz_block-1));i++)
        for(int j=0;j<sz_block;j++)rmq_mask[i][j]=(int*)malloc(sz_block*sizeof(int));

        block_mask=(int*)calloc(n_blocks,sizeof(int));
        for(int i=0;i<n_blocks;i++)
        for(int j=i*sz_block+1;j<(i+1)*sz_block;j++){
          block_mask[i]<<=1;
          if(j<n&&depths[trav[j]]>depths[trav[j-1]])block_mask[i]|=1;
        }

        std::vector<bool> computed(1<<(sz_block-1));
        for(int i=0;i<n_blocks;i++){
          if(!computed[block_mask[i]]){
          computed[block_mask[i]]=1;
          for(int l=0;l<sz_block;l++){
            rmq_mask[block_mask[i]][l][l]=l;
          for(int r=l+1;r<sz_block;r++){
            if(i*sz_block+r<n&&depths[trav[i*sz_block+r]]<depths[trav[i*sz_block+rmq_mask[block_mask[i]][l][r-1]]])
              rmq_mask[block_mask[i]][l][r]=r;
            else rmq_mask[block_mask[i]][l][r]=rmq_mask[block_mask[i]][l][r-1];
          }
        }}
        }
        int h=std::__lg(n_blocks)+2;
        rmq_blocks=(int**)malloc(n_blocks*sizeof(int*));
        for(int i=0;i<n_blocks;i++)rmq_blocks[i]=(int*)malloc(h*sizeof(int));
        for(int i=0;i<n_blocks;i++)rmq_blocks[i][0]=i*sz_block+rmq_mask[block_mask[i]][0][std::min(sz_block,n-i*sz_block)-1];

        for(int j=1;j<h;j++)
        for(int i=0;i+(1<<j)-1<n_blocks;i++){
          if(depths[trav[rmq_blocks[i][j-1]]]>depths[trav[rmq_blocks[i+(1<<(j-1))][j-1]]])
            rmq_blocks[i][j]=rmq_blocks[i+(1<<(j-1))][j-1];
          else rmq_blocks[i][j]=rmq_blocks[i][j-1];
        }
      }
      rmq(std::vector<int> &a){
        int n=a.size();
        int* arr=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)arr[i]=a[i];
        new (this) rmq(arr,n);
        free(arr);
      }
      ~rmq(){
        free(trav);
        free(depths);
        free(first_occ);
        free(block_mask);
        for(int i=0;i<(1<<(sz_block-1));i++)
        for(int j=0;j<sz_block;j++)free(rmq_mask[i][j]);
        for(int i=0;i<(1<<(sz_block-1));i++)free(rmq_mask[i]);
        free(rmq_mask);
        for(int i=0;i<n_blocks;i++)free(rmq_blocks[i]);
        free(rmq_blocks);
        }
      int operator()(int l, int r){
        l=first_occ[l];
        r=first_occ[r];
        if(l>r)std::swap(l,r);
        int l_block=l/sz_block;
        int r_block=r/sz_block;
        if(l_block==r_block)return trav[rmq_mask[block_mask[l_block]][l%sz_block][r%sz_block]+l_block*sz_block];
        else{
          int ans;
          int min_l_block=trav[rmq_mask[block_mask[l_block]][l%sz_block][sz_block-1]+l_block*sz_block];
          int min_r_block=trav[rmq_mask[block_mask[r_block]][0][r%sz_block]+r_block*sz_block];
          ans=(depths[min_l_block]<depths[min_r_block])?min_l_block:min_r_block;
          if(r_block-l_block>1){
            l_block++;
            r_block--;
            int j=std::__lg(r_block-l_block+1);
            int min_l_blocks=trav[rmq_blocks[l_block][j]];
            int min_r_blocks=trav[rmq_blocks[r_block-(1<<j)+1][j]];
            if(depths[ans]>depths[min_l_blocks])ans=min_l_blocks;
            if(depths[ans]>depths[min_r_blocks])ans=min_r_blocks;
          }
          return ans;
        }
      }
  };
#endif
