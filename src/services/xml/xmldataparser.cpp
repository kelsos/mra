#include "xmldataparser.h"

XmlDataParser::XmlDataParser()
{
    //default constructor

}

void XmlDataParser::parseData(QString fileName)
{
    QFile *file = new QFile(fileName);
    file->open(QIODevice::ReadOnly);
    xmlStreamReader.setDevice(file);
    QByteArray ba;
    PublisherInfo pub;
    GenreInfo gen;
    AuthorInfo auth;
    MangaInfo mInfo;
    MangaGenres mGen;
    MangaAuthors mAuth;
    QString coverString;

    while(!xmlStreamReader.atEnd())
    {
        xmlStreamReader.readNext();
        if (xmlStreamReader.isStartElement())
        {
            if(xmlStreamReader.name()=="Publishers"||xmlStreamReader.name()=="Genres"||
                    xmlStreamReader.name()=="Authors"  ||xmlStreamReader.name()=="Mangas"||
                    xmlStreamReader.name()=="MangaAuthors"||xmlStreamReader.name()=="MangaGenres")
                currentCategory = xmlStreamReader.name().toString();
            currentTag = xmlStreamReader.name().toString();
        }
        else if (xmlStreamReader.isEndElement())
        {
            if(xmlStreamReader.name()=="Publisher")
            {
				DatabaseManager::Instance()->getImporter()->insertPublisherData(&pub);
                pub.clear();
            }
            else if(xmlStreamReader.name()=="Genre")
            {
                DatabaseManager::Instance()->getImporter()->insertGenreData(&gen);
                gen.clear();
            }
            else if(xmlStreamReader.name()=="Author")
            {
                DatabaseManager::Instance()->getImporter()->insertAuthorData(&auth);
                auth.clear();
            }
            else if (xmlStreamReader.name()=="Manga")
            {

                ba.append(coverString);
                mInfo.setMangaCover(QByteArray::fromBase64(ba));
                DatabaseManager::Instance()->getImporter()->insertMangaData(&mInfo);
                coverString.clear();
                mInfo.clear();
                ba.clear();

            }
            else if (xmlStreamReader.name()=="MangaGenre")
            {
                DatabaseManager::Instance()->getImporter()->insertMangaGenre(&mGen);
                mGen.clear();
            }
            else if(xmlStreamReader.name()=="MangaAuthors")
            {
                DatabaseManager::Instance()->getImporter()->insertMangaAuthor(&mAuth);
                mAuth.clear();
            }
        }
        else if (xmlStreamReader.isCharacters() && !xmlStreamReader.isWhitespace())
        {
            if (currentCategory=="Publishers")
            {
                if (currentTag=="PublisherID")
                    pub.setPublisherId(xmlStreamReader.text().toString().toUInt());
                else if (currentTag=="PublisherName")
                    pub.setPublisherName(xmlStreamReader.text().toString());
                else if (currentTag=="PublisherCountry")
                    pub.setPublisherCountry(xmlStreamReader.text().toString());
                else if (currentTag=="PublisherWebsite")
                    pub.setPublisherWebsite(xmlStreamReader.text().toString());
                else if (currentTag=="PublisherNote")
                    pub.setPublisherNote(xmlStreamReader.text().toString());
            }
            else if(currentCategory=="Genres")
            {
                if (currentTag=="GenreID")
                    gen.setGenreId(xmlStreamReader.text().toString().toUInt());
                else if (currentTag=="GenreName")
                    gen.setGenreName(xmlStreamReader.text().toString());
            }
            else if (currentCategory=="Authors")
            {
                if (currentTag== "AuthorID")
                    auth.setAuthorId(xmlStreamReader.text().toString().toUInt());
                else if (currentTag== "AuthorName")
                    auth.setAuthorName(xmlStreamReader.text().toString());
                else if (currentTag== "AuthorCountry")
                    auth.setAuthorNationality(xmlStreamReader.text().toString());
                else if (currentTag== "AuthorBirth")
                    auth.setAuthorBirthday(QDateTime::fromString(xmlStreamReader.text().toString(),Qt::ISODate));
                else if (currentTag== "AuthorWebsite")
                    auth.setAuthorWebsite(xmlStreamReader.text().toString());
            }
            else if (currentCategory=="Mangas")
            {
                if (currentTag== "MangaID")
                    mInfo.setMangaId(xmlStreamReader.text().toString().toUInt());
                else if (currentTag== "MangaTitle")
                    mInfo.setMangaTitle(xmlStreamReader.text().toString());
                else if (currentTag== "MangaYearOfPublish")
                    mInfo.setMangaPublicationDate(QDateTime::fromString(xmlStreamReader.text().toString(),Qt::ISODate));
                else if (currentTag== "MangaStatus")
                    mInfo.setMangaPublicationStatus(xmlStreamReader.text().toString());
                else if (currentTag== "MangaPublisherID")
                    mInfo.setMangaPublisherId(xmlStreamReader.text().toString().toUInt());
                else if (currentTag== "MangaDescription")
                    mInfo.setMangaDescription(xmlStreamReader.text().toString());
                else if (currentTag== "MangaCover")
                    coverString+=xmlStreamReader.text().toString();
            }
            else if (currentCategory=="MangaGenres")
            {
                if (currentTag=="MangaID")
                    mGen.setMangaId(xmlStreamReader.text().toString().toUInt());
                else if (currentTag=="GenreID")
                    mGen.setGenreId(xmlStreamReader.text().toString().toUInt());
            }
            else if (currentCategory=="MangaAuthors")
            {
                if(currentTag=="MangaID")
                    mAuth.setAuthorId(xmlStreamReader.text().toString().toUInt());
                else if(currentTag=="AuthorID")
                    mAuth.setAuthorId(xmlStreamReader.text().toString().toUInt());
            }
        }

    }
    if(xmlStreamReader.error() && xmlStreamReader.error()!= QXmlStreamReader::PrematureEndOfDocumentError)
    {
        qWarning() << "XML ERROR:" << xmlStreamReader.lineNumber() << ": " << xmlStreamReader.errorString();
    }
}
