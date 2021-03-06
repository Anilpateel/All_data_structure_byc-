#include <iostream>

using namespace std;
class node{
   public:
   int data;
   node *left;
   node *right;

     node(int val)
     {
         data=val;
         left=NULL;
         right=NULL;
     }


};
class Traversals{

  public:
      void PreOrder(node* root){
       if(root!=NULL)
       {
           cout<<root->data<<" ";
           PreOrder(root->left);
           PreOrder(root->right);
       }

     }
      void PostOrder(node* root){
       if(root!=NULL)
       {
           PostOrder(root->left);
           PostOrder(root->right);
           cout<<root->data<<" ";

       }
    }
      void InOrder(node* root){
       if(root!=NULL)
       {

           InOrder(root->left);
           cout<<root->data<<" ";
           InOrder(root->right);
       }

     }

        int IsBST(node* root)
        {
           static node* pre=NULL;

          if(root!=NULL)
          {
             if(!IsBST(root->left))
             {
                 return 0;
             }

             if(pre!=NULL && root->data <=pre->data)
             {
                 return 0;
             }
            pre=root;
            return IsBST(root->right);
          }
          else
          {

              return 1;
          }

       }

   node *Search(node * root ,int key)
       {
           if(root==NULL)
           {
               return NULL;
           }
           else
           {
               if(key==root->data)
               {
                   return root;
               }
               else if(key<root->data)
               {
                   return Search(root->left,key);
               }
               else
               {
                   return Search(root->right,key);
               }

           }

       }

       node *IterativeSearch(node * root ,int key)
       {
           if(root==NULL)
           {
               return NULL;
           }
           else
           {
               while(root!=NULL)
               {
                   if(key==root->data)
                   {
                       return root;
                   }
                   else if(key<root->data)
                   {
                       root=root->left;
                   }
                   else
                   {
                       root=root->right;
                   }

               }


           }

       }

       void insertion(node* root ,int val)
       {
           node* prev;
           if(root==NULL)
           {
               cout<<"This operation is not possible because the tree is empty"<<endl;
           }
           else
           {
             while(root!=NULL)
           {
               prev=root;

               if(val==root->data)
               {
                   cout<<"Operation is not possible because Val is already present"<<endl;
                    return ;

               }else if(val<root->data)
               {
                   root=root->left;
               }
               else
               {
                   root=root->right;
               }
           }

           node* n =new node(val);
           if(val<prev->data)
           {
               prev->left=n;
           }
           else
           {
               prev->right=n;
           }

           }

       }
  node* inOrderPredecrssor( node* root)
    {

      root=root->left;
      while(root->right!=NULL)
      {
          root=root->right;
      }
      return root;

    }
       node* deletenode(node* root,int val)
       {
           node* iPre;
             if(root==NULL)
             {
                 cout<<"This operation is not possible because BST is empty"<<endl;
             }
             if(root->left==NULL && root->right==NULL)
             {
                 delete(root);
                 return NULL;
             }

                 if(val<root->data)
                 {
                    root->left= deletenode(root->left,val);
                 }
                 else if(val>root->data)
                 {
                    root->right= deletenode(root->right,val);
                 }
                 else
                 {
                     iPre = inOrderPredecrssor(root);
                     root->data=iPre->data;
                     root->left=deletenode(root->left,iPre->data);
                 }

          return root;
       }


};
int main()
{

   Traversals traversals;
   node *p = new node(5);
   node *p1 = new node(3);
   node *p2 = new node(6);
   node *p3 = new node(1);
   node *p4 = new node(4);
//        5
//        /\
//       3  6
//       /\
//      1  4
//

   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
  cout<<"PreOder traversal "<<endl;
  traversals.PreOrder(p);
  cout<<endl;
  cout<<"PostOder traversal "<<endl;
  traversals.PostOrder(p);
  cout<<endl;
  cout<<"InOder traversal "<<endl;
  traversals.InOrder(p);
  cout<<endl;
  cout<<traversals.IsBST(p);
  cout<<endl;
  node *n1= traversals.Search(p,1);
   if(n1!=NULL)
   {
       cout<<"Found "<<n1->data;
   }
   else
   {
       cout<<"Not found"<<endl;
   }
  cout<<endl;
  traversals.deletenode(p,5);
  cout<<"InOder traversal "<<endl;
  traversals.InOrder(p);
  cout<<endl;
    return 0;
}
