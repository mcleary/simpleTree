#ifndef QUERCUS_FOLDER_H
#define QUERCUS_FOLDER_H

#include "../../../includes.h"
#include "../../../Model/Tree.h"

namespace simpleTree
{
  class Tree;
}

class Quercus_folder : public QDialog
{
        Q_OBJECT


public:
    /** \brief Default contrstructor
     * \param parent: The parent QT class (main UI class)
     * */
    Quercus_folder(QWidget * parent = 0);
    ~Quercus_folder();

    /**
     * @brief the method to calculate all the models for one
     * specific folder with thresholds set to the ones used
     * in the publication
     */
    void
    compute();


signals:
    /**
     * @brief emitCloud emits the point cloud
     * @param cloud the cloud
     */
    void
    emitCloud(PointCloudI::Ptr cloud, bool updateVisu = false);


    /**
     * @brief emitQString emits A QString
     * @param str the emitted String
     * @param firstLine set true if you want to print a line above str
     * @param secondLine set true if you want to print a line below str
     */
    void
    emitQString(QString str = "", bool firstLine = false, bool secondLine = false);

    /**
     * @brief emitTreeID emits the QString of the treeID
     * @param ID the emitted Tree ID
     */
    void
    emitTreeID(QString ID = "");

    /**
     * @brief emitTree emits the Tree model
     * @param tree_ptr the emitted tree model
     */
    void
    emitTree(boost::shared_ptr<simpleTree::Tree> tree_ptr, bool updateView = false);

    /**
     * @brief emitE1 emits a vector of the first PC
     * @param e1 the emitted PC
     */
    void
    emitE1(std::vector<float> e1);

    /**
     * @brief emitE2 emits a vector of the second PC
     * @param e2 the emitted PC
     */
    void
    emitE2(std::vector<float> e2);

    /**
     * @brief emitE3 emits a vector of the third PC
     * @param e3 the emitted PC
     */
    void
    emitE3(std::vector<float> e3);

    /**
     * @brief emitIsStem emits a vector of stem point information
     * @param isStem the stem point information
     */
    void
    emitIsStem(std::vector<bool> isStem);

    /**
     * @brief emitProgress The progress emitted in a percentage number
     * @param progress The progress in percentage
     */
    void
    emitProgress(int progress);

private:


    /**
     * @brief setsTheCoefficients for the SphereFollowing
     */
    void
    setStartCoefficient();



    /**
     * @brief _method_coefficients The method coefficients for the SphereFollowing routine
     */
    Method_Coefficients _method_coefficients;

    PointCloudI::Ptr _cloud_Ptr;




    /**
     * @brief _a Parameter for allometry;
     */
    float _a = 240.559;

    /**
     * @brief _b Parameter for allometry;
     */
    float _b = 2.72;

    /**
     * @brief _fac Parameter for allometry;
     */
    float _fac = 2.5;

    /**
     * @brief _minRadius Parameter for allometry;
     */
    float _minRadius = 0.0025;

    /**
     * @brief _result_string A string to store result text in
     */
    QString _result_string;
};

#endif // QUERCUS_FOLDER_H
