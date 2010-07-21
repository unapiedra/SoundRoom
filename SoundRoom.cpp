#include <stdio.h>
// #include <math.h>
// #include <complex.h>

#include <QtGui/QPainter>
#include <QtGui/QColormap>

#include <Eigen/Core>

#include "SoundRoom.h"

SoundRoom::SoundRoom()
{
	this->resize(300, 300);
	//TODO make non-resizable!
	m_origin = QPoint(0, height()/2); //! Origin is on lefthand side in the middle
	
	m_speakerlist << Speaker(QPoint(10,0), 440, 255);
}


SoundRoom::~SoundRoom()
{}

void SoundRoom::paintEvent(QPaintEvent* )
{
	drawSpeaker(&m_speakerlist.first());
	
	int x, y;
	for(x=0; x<300; x +=3)
	{
		for(y=0; y<300; y +=3)
		{
			QPoint point(QPoint(x, y));
			shadePoint(&point);
		}
	}
}

//! Shades a point. @param point Point to be shaded.
void SoundRoom::shadePoint(QPoint* point)
{
	QPainter painter(this);
	
// 	painter.translate(m_origin); 
	
	double local_volume = 0;
	foreach(const Speaker &speaker, m_speakerlist)
	{
// 		local_volume += speaker.getPosition();
	}
	QColor intensity(0, 0, 160, local_volume);
	painter.setBrush(intensity);
	
 	painter.drawPoint(*point); // put back in once more than one point is drawn.
// 	painter.translate(*point);
// 	painter.drawRect(-4, -4, 8, 8);
}

//! Draws a speaker. @param speaker Speaker to be drawn.
void SoundRoom::drawSpeaker(Speaker* speaker)
{
	QPainter painter(this);
	
	painter.translate(m_origin);
		
	painter.setBrush(Qt::red);
	
	painter.translate(speaker->getPosition());
	painter.drawRect(-4, -4, 8, 8);
}
#include "SoundRoom.moc"
