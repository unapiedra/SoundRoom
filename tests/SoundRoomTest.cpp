#include "SoundRoomTest.h"
#include <QtTest/QTest>

#include <stdio.h>

#include "../speaker.h"

void SoundRoomTest::initTestCase()
{
	m_uut = new SoundRoom();
}

void SoundRoomTest::init()
{
}

void SoundRoomTest::cleanup()
{
}

void SoundRoomTest::cleanupTestCase()
{
	delete m_uut;
}

//! Test that SoundRoom inherits from QWidget
void SoundRoomTest::testSuperClass()
{
	QString name = m_uut->metaObject()->superClass()->className();
	QCOMPARE(name, QString("QWidget"));
}

//! Assert that size of window is 300px times 300px.
void SoundRoomTest::testWindowSize()
{
	QCOMPARE(m_uut->size(), QSize(300, 300));
}

//! Test that one speaker exists at position (0, 0)
void SoundRoomTest::testSpeaker()
{
	QCOMPARE(m_uut->m_speakerlist.count(), 1);
	QCOMPARE(m_uut->m_speakerlist.first().getPosition(), QPoint(10,0));
}

//! Give speaker a frequency of 440Hz
void SoundRoomTest::testSpeakerfrequency()
{
	Speaker speaker = m_uut->m_speakerlist.first();
	speaker.setFrequency(440.0);
	QCOMPARE(speaker.getFrequency(), 440.0);
}


QTEST_MAIN(SoundRoomTest)
#include "SoundRoomTest.moc"
