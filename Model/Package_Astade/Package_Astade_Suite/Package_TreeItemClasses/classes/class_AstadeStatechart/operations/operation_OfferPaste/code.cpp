//~~ bool OfferPaste() [AstadeStatechart] ~~
return ((dynamic_cast<AstadeState*>(globalCopySource) != NULL) || (dynamic_cast<AstadeTransition*>(globalCopySource)));