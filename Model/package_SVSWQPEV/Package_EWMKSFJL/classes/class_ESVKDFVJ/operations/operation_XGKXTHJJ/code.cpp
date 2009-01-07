wxString aLabel;
aLabel.Printf("%d x %d pixel",xPixelSlider->GetValue(), yPixelSlider->GetValue());

sliderSizer_staticbox->SetLabel(aLabel);

graphicPanel->SetVirtualSize(xPixelSlider->GetValue(), yPixelSlider->GetValue());