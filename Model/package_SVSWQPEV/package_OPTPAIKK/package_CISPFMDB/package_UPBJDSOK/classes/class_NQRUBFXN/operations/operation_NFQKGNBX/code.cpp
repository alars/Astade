// we rely upon the fact that both Astade tree-view and AstadeGenerate set
// the cwd to the directory of the model root node - there's no other generic
// way to find the root (other than repeatedly backing upwards which could
// kill performance)
return wxFileName::GetCwd();
