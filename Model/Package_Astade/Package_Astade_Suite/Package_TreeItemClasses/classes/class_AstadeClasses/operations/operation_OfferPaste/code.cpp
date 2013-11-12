//~~ bool OfferPaste() [AstadeClasses] ~~
return ((dynamic_cast<AstadeClass*>(globalCopySource) != NULL) ||
         (dynamic_cast<AstadeStatechart*>(globalCopySource) != NULL));