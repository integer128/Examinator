#include "theoryreader.h"

TheoryReader::TheoryReader()
    : m_processor { new database::Processor {} }
{

}

TheoryReader::~TheoryReader()
{

}

TheoryData TheoryReader::requestTheoryDataById(const int &id)
{
    database::DBVariant entries { m_processor->requestTheoryDataById(id) };

    return transform(entries.second);
}

TheoryData TheoryReader::transform(const std::vector<QVariant> &source)
{
    return TheoryData
    {
        source[0].toInt(),
        source[1].toString(),
        source[2].toString(),
        source[3].toBool()
    };
}

void TheoryReader::requestSaveChanges(const TheoryData &data)
{
    m_processor->requestSaveChanges(data);
}
