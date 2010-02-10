bool retVal = (GetModificationTime() > GetImpGenerationTime());
retVal |= (GetModificationTime() > GetSpecGenerationTime());
return retVal;