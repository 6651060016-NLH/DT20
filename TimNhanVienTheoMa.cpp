Node* searchBST(Node* root, string maSV){
  if(root==NULL||root->data.maNV==maNV){
    return root;
  }
  if(maNV<root->data.maSV){
    return searchBST(root->left,maNV);
  }
  return searchBST(root->right.maSV);
}
