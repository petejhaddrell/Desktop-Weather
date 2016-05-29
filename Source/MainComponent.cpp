/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
    startTimer (10000);
    weather.connect();
    background.setCurrentColour (Colours::black);
}

MainContentComponent::~MainContentComponent()
{
    stopTimer();
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (background.getCurrentColour());

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainContentComponent::timerCallback()
{
    weather.connect();
    setColour();
}

void MainContentComponent::setColour()
{
    setBackgroundColour (date.getHours());
    std::cout << date.getHours() << "\n";
    repaint();
}

void MainContentComponent::setBackgroundColour (int tod)
{
    if (tod <= 7 || tod >= 22)
    {
        background.setCurrentColour (Colours::orange);
    }
    else if (tod > 7 && tod <= 13)
    {
        background.setCurrentColour (Colours::lightblue);
    }
    else if (tod > 13 && tod <= 19)
    {
        background.setCurrentColour (Colours::blue);
    }
    else if (tod > 19 && tod < 22)
    {
        background.setCurrentColour (Colours::orange);
    }
}
