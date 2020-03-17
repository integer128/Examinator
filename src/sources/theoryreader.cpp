#include "theoryreader.h"

TheoryReader::TheoryReader()
{

}

TheoryReader::~TheoryReader()
{

}

TheoryData TheoryReader::requestTheoryDataById(const short &id)
{
    std::pair<database::DBResult, std::vector<QVariant> > entries
    { m_processor->requestTheoryDataById(id) };

    return transform(entries.second);
}

TheoryData TheoryReader::transform(const std::vector<QVariant> &source)
{
    return TheoryData
    {
        static_cast<short>(source[0].toInt()),
        source[1].toString(),
        source[2].toString()
    };
}
