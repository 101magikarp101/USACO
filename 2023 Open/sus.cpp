#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
class TrieNode {
   public:
   int leaf;
   TrieNode *child[2];
   TrieNode(){
      leaf = 0;
      child[0] = child[1] = NULL;
   }
};
void insert(TrieNode *root, int matrix[][MAX], int n, int row_index){
   TrieNode * temp = root;
   for (int i=0; i<n; i++) {
      if(temp->child[ matrix[row_index][i] ] == NULL)
         temp->child[ matrix[row_index][i] ] = new TrieNode();
         temp = temp->child[ matrix[row_index][i] ];
      }
      temp->leaf = row_index +1 ;
   }
   pair<int, int>get_max_bit_diff(TrieNode * root, int matrix[][MAX], int n, int row_index) {
      TrieNode * temp = root;
      int count = 0;
      for (int i= 0 ; i < n ; i++) {
         if (temp->child[ matrix[row_index][i] ] != NULL)
            temp = temp->child[ matrix[row_index][i] ];
         else if (temp->child[1 - matrix[row_index][i]] != NULL) {
            temp = temp->child[1- matrix[row_index][i]];
            count++;
         }
      }
      int leaf_index = temp->leaf;
      int temp_count = 0 ;
      temp = root;
      for (int i= 0 ; i < n ; i++) {
         if (temp->child[ 1 - matrix[row_index][i] ] !=NULL) {
            temp = temp->child[ 1- matrix[row_index][i] ];
            temp_count++;
         }
         else if (temp->child[ matrix[row_index][i] ] != NULL)
            temp = temp->child[ matrix[row_index][i] ];
      }
      pair <int ,int> P = temp_count > count ? make_pair(temp_count, temp->leaf): make_pair(count, leaf_index);
      return P;
}
void get_max_diff( int mat[][MAX], int n, int m) {
   TrieNode * root = new TrieNode();
   insert(root, mat, m, 0);
   int max_bit_diff = INT_MIN;
   pair<int ,int> pr, temp ;
   for (int i = 1 ; i < n; i++) {
      temp = get_max_bit_diff(root, mat, m ,i);
      if (max_bit_diff < temp.first ) {
         max_bit_diff = temp.first;
         pr = make_pair( temp.second, i+1);
      }
      insert(root, mat, m, i );
   }
   cout << "(" << pr.first <<", "<< pr.second << ")";
}
int main() {
   int mat[][MAX] = {
      {1 ,1 ,1 ,1 },
      {1, 0, 1 ,1},
      {0 ,1 ,0 ,0},
      {1 ,0 ,0 ,0}
   };
   get_max_diff(mat, 4, 4) ;
}