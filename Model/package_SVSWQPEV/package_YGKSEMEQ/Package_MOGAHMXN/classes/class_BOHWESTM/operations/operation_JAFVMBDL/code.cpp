// if yes, we have to remove the exiting one first
//Remove(name);

int index = Add(bitmap, wxNullBitmap);
myIconNameMap[name] = index;
myIconBitmapMap[index] = bitmap;

return index;