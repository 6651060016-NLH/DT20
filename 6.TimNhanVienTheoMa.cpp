Node* searchBST(Node* root, string maNV){
  if(root==NULL||root->data.maNV==maNV){
    return root;
  }
  if(maNV<root->data.maNV){
    return searchBST(root->left,maNV);
  }
  return searchBST(root->right.maNV);
}
