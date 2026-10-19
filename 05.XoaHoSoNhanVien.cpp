Node* deleteNode(Node* root, string maNV{
if(root == NULL) return root;
if(maNV < root->data.maNV){
  root->left = deleteNode(root->left, maNV);
}else if(maNV > root->data.maNV){
  root->right= deleteNode(root->right, manNV);
}else{
  if(root->left==NULL){
    Node* temp = root->right;
    delete root;
    return temp;
  }else if(root->right==NULL){
    Node* temp = root->left;
    delete root;
    return temp;
  }
Node* temp = findMin(root->right);
root->data=temp->data;
root->right=deleteNode(root->right,temp->data.maMV);
}
return root;
}



