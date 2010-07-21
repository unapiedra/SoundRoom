/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "speaker.h"

Speaker::Speaker(QPoint pos, double frequency, double volume) : m_pos(pos), m_frequency(frequency), m_volume(volume)
{
}


Speaker::~Speaker()
{
}


void Speaker::setFrequency(double frequency)
{
	m_frequency = frequency;
}

