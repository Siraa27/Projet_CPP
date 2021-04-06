#ifndef COUCHE_HPP
#define COUCHE_HPP
/*!
 * \file Couche.hpp
 * \brief Les propritées d'une couche : ses nombre de neurones ainsi que sa fonction d'activation
 */
class Couche{
    protected : 
        int nbNeurones; 
        Neurone Neurones[]; 
        int indice ; 
    public :
        Couche (const nbNeurones); // le nb de Neurones d'une couche ne change pas une fois choisit au cours du programmes
        double foncActivation();
}
#endif