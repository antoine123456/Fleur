#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
/// @brief Compose la base de Flower et Bouquet
/// @see https://godbolt.org/z/ooK67xeGq
/// @see https://www.plantuml.com/plantuml/uml/TL1DQyKW4BpxAuHUj3savmU51-zl5CHcVUc27q4tkPJsjrVZYmsOtfoTSMTchubqfCLPDbgT4hy5DmTlFBtxOH0RIaX63iCNU-698lg9E-MrCncZ9pul7nP7XP3ntGPDcPuZZfKloEBT4Bg_WPxAkra9cT6AEOQs_ETyl0O4hW54e_bpnqVZmch-anp6aw7R9reGEK-tHQbevgYKa6-l1wvsopzhEo7FkDRrd2xD-ref4-MWud7Uykv5pRXkA-zpLOjGZhs3hAoAFG7wcWXXWudWSdduJtiUoSVW4x6dtWHXMuyWsJUx6W-Bixy0
/// @see https://www.plantuml.com/plantuml/uml/TLB1ZjGm3BttAo9nwO0gSLx1Qc616n8IUuyoYQSOqgGaRXa9s6ydIQrfXkoUOljPzdilleka0YsJxRHLCOfxFytUWQFVtIiHAQ0RnIITcY3bw4ZCoz6YbcXIVh9UKOBdW9hnb5ay0U6q5zIOudroVqZPYcchikBnwVBgqGXbJ7-1nSi63p3v5PvhgSeZqFqtjAP7HyqKAGFCGSh-yFRrZh6s4MXJLzYr66jz3axAMraHg1ZQixqvRfikYxTf9MwxQWhPR4vo9tl83D1jZD2KD9AvkU7z8p2VWz3UHUfUj4lGbF5e3jrVlfHFrl-2aCw4epBtSO-ltTqhaNt9yzAx3tplbvyBfCCR2jku7B-3fg-a259fJR4FR-fl5RVPbZNXKkVl3U2wWTtN7avVicSFoOq7_rdz09d0e_TMm7d6e0YzAyCbBwIgCobXEhLxfRrMmfL2DqSCDQUh6MXlbh5QrULQ5nTnT634PlqvDzQis61qIBN1sZiAthuRuThqNLz_BVUfpnfubhBwutd-K7JNnU9jdp-F6ObX-7Exw-YsG_Y_UWVEB9Fz1m00
class Component
{
public:
    /// @brief Nom du Component
    string m_name;
    /// @brief Identifiant du Component
    int public_id;
    /// @brief Prix du Component
    float m_price;
    /// @brief Durée de vie du Component
    int m_lifetime;
    /// @brief Age du Component
    int m_age;
    /// @brief Constructeur de Component
    Component() { std::cout << "Constructeur de Component" << std::endl; }
    /// @brief Destructeur de Component
    virtual ~Component() {}
    /// @brief Ajoute un Component au Composite
    /// @param c Component à ajouter
    virtual void add(Component *){};
    /// @brief Retire un Component du Composite
    /// @param c {Component} Component à ajouter
    virtual void remove(Component *){};
    /// @brief Retourne un Component désigné du Composite
    /// @param idx {unsigned int} Identifiant du Component à réccuperer
    /// @return Component {Component}
    virtual Component *getChild(int) { return nullptr; };
    /// @brief Montre des attributs du Component
    virtual void __repr__() = 0;
    /// @brief Renvoit le prix du Bouquet
    /// @return m_price {float}
    virtual float get_price() { return m_price; };
    /// @brief Renvoit la lifetime du Component
    /// @return m_lifetime_ {int}
    virtual float get_lifetime() { return m_lifetime; };
    /// @brief Retourne l'age du Component
    /// @return m_age {int}
    virtual float get_age() { return m_age; };
    /// @brief Change le nom du Component
    /// @param name {string} Nom du Component
    virtual void set_name(string name) { m_name = name; };
    /// @brief Change le prix du Component
    /// @param price {float} Prix du Component
    virtual void set_price(float price) { m_price = price; };
    /// @brief Change la lifetime du Component
    virtual void set_lifetime(int lifetime) { m_lifetime = lifetime; };
    /// @brief Avance l'age du Component
    void age() { m_age++; }
    /// @brief Retourne l'identifiant du Component
    /// @return public_id {int}
    int get_id() { return public_id; };
    /// @brief Renvoit le nom du Component
    /// @return m_name {std::string}
    std::string get_name() const { return m_name; };

protected:
    /// @brief Change l'public_id du Component
    /// @param id {int} Identifiant du Component
    virtual void set_id(int id) { public_id = id; };
    /// @brief Autorise Fabrique à accéder à l'public_id du Component
    friend class Fabrique;
};
/// @brief Déclare la classe Flower (sous-Component)
/// @see https://www.plantuml.com/plantuml/uml/SoWkIImgAStDuKhEIImkLd3BoIzFBQhcqeQoD3I1p3eaTbb-Pef2V7nHQa5HV3n2f3Yr93unFLKZCwz40KXhSjLoEQJcfG0D1W00
class Flower : public Component
{
public:
    /// @brief Constructeur de Flower
    Flower() { cout << "Constructor Flower" << endl; }
    /// @brief Destructeur de Flower
    ~Flower() {}
    /// @brief Présentation d'une Flower
    /// \example Flower::__repr__ \n Flower fleur("Rose",5,12,0,0) \n fleur.__repr__() \n>Rose \n- Age de la fleur : 1\n- Prix de la fleur : 5\n- Durée de vie de la fleur : 12
    void __repr__()
    {
        cout << "> " << get_name() << endl;
        cout << " - Age de la fleur : " << get_age() << endl;
        cout << " - Prix de la fleur : " << get_price() << endl;
        cout << " - Durée de vie de la fleur : " << get_lifetime() << endl;
        drawFlower(get_name());
    };
    /// @brief Change l'm_age de la Flower
    /// @param age {int} Age à affecter
    void set_age(int age) { m_age = age; };
    /// @brief Dessine une Flower
    /// @param name {string} Nom de la Flower
    void drawFlower(string name)
    {
        if (name == "Rose")
        {
            string flower_ascii4 = R"(
    _,--._.-,
   /\_r-,\_ )
.-.) _;='_/ (.;
 \ \'     \/S )
  L.'-. _.'|-'
 <_`-'\'_.'/
   `'-._( \
    ___   \\,      ___
    \ .'-. \\   .-'_. /
     '._' '.\\/.-'_.'
        '--``\('--'
              \\
              `\\,
                \|
                )";
            cout << flower_ascii4 << endl;
        }
        else if (name == "Tulipe")
        {
            string flower_ascii4 = R"(
     /\^/`\
    | \/   |
    | |    |
    \ \    /
     '\\//'
       ||
       ||
       ||
       ||  ,
   |\  ||  |\
   | | ||  | |
   | | || / /
    \ \||/ /
     `\\//`
    ^^^^^^^^
)";
            cout << flower_ascii4 << endl;
        }
        else if (name == "Jonquille")
        {
            string flower_ascii4 = R"(
      __.,  _.-.       
    -'    '      .-'-.
  .',      '    '     '
  ', `,     .  '.-.   '
   '   \    ' ."   ".'
    '.' \   ;.",    "-._
     '   '. ,"  "-."    '.
      _.--'.    ." ,.--.  .
   , '     "-..".-'     \ '
 -`     _.''".    ' .    '
'     -'   "  '-     '.
'    '    "     '      '
 '.'     "       '    .'
   ',    "        ' .'
         "        ,'
         "
         "
       _."._)";
            cout << flower_ascii4 << endl;
        }
        else if (name == "Marguerite")
        {
            string flower_ascii4 = R"(

             .-.'  '.-.
          .-(   \  /   )-.
         /   '..oOOo..'   \
 ,       \.--.oOOOOOOo.--./
 |\  ,   (   :oOOOOOOo:   )
_\.\/|   /'--'oOOOOOOo'--'\
'-.. ;/| \   .''oOOo''.   /
.--`'. :/|'-(   /  \   )-'
 '--. `. / //'-'.__.'-;
   `'-,_';//      ,  /|
        '((       |\/./_
          \\  . |\; ..-'
           \\ |\: .'`--.
            \\, .' .--'
             ))'_,-'`
            //-'
           // 
          //
         |/)";
            cout << flower_ascii4 << endl;
        }
        else
        {
            cout << "Unknown flower name" << endl;
        }
    }
};
/// @brief Subject pour permetre la definition d' Observer (Subject-Observer)
/// @see https://www.plantuml.com/plantuml/uml/PLB1hjCm4BptAtmCe4YSd-3fmOC31mHIUxSSUvikEDvWRw8YeD-ERPmueJTxPZ8xtibJOELv6kn1MnM2U4_JZmdurw4Lw5Y4gVi6ce-i628qnpFvD-APXf4SHC5ByIX6ZtFafRwWDHvS59ujAHQQuFpLeuOJ3d2Yp-exo4XsH5R0TKIl6CbbSra6yaRvIjnAdEP5l2IwXtzPCZ0J6X4M9CTDfvLInZIRf7ebF0mqmnstkQT1p-avpUG2zWvC7e_cceGrLJ6K4Xsob1NHvDYJVTVleyhwlcR_t8sNXz5dhxPuAQi_NiSFYc4Ffjqcw4yfxvZR-hyyYIO2WSt3mzBVbow0dy6dzkRbaWAWvqbPSIjEDRjYLlhIr0-fd5Q5WQpGv0ANPQsS8yRpp-XMH-pRVFkwKljUgs5fDqlpQm9xTBs88Rhxd-AJQMg8CYnYQLcbFj6sln-NdHsUm9bfi7y1
class Subject;
/// @brief Observer (Subject-Observer)
/// @see https://godbolt.org/z/qMKrsoY7M
/// @see https://www.plantuml.com/plantuml/uml/SoWkIImgAStDuKhEIImkLl1FAaujAaijgkPILiZCAr4eYCzCuTA62siav-SLbu1bCbCqWH9bcK3TYJaATN0LoA9b-Paf2gK5AOabgHh1fKbPgSab2bh548QchG529TZ4zDGIpnGDa7WjbqDgNWhGLG00
class Observer
{
public:
    /// @brief Constructeur d'un Observer, assigne le p_id
    /// @param id {int} Identifiant de l'Observer
    Observer(const int id) : p_id(id) {}
    /// @brief Destructeur de l'Observer
    virtual ~Observer() {}
    /// @brief Atteste de la maj d'un Subject
    virtual void update(Subject *subject) = 0;
    /// @brief Réccupère l'identifiant de l'Observer
    /// @return p_id {int}
    virtual int getId() = 0;

protected:
    /// @brief Identifiant de l'Observer
    int p_id;
};
/// @brief Implémentation de la classe Subject + ajout d'identifiant
/// @see https://www.plantuml.com/plantuml/uml/HL2_pi8W4DzvYXlX-sBYtAZfwkJG1p0Ki68g9DoLn1XzTYcbPUll_vKMIGQQdYDJeqI4RkeVHj6RxS0w0bpWrUf48EccYGdwS81BZoP44_xW1745x1-YJNLoX6zfuc8clTKWYQIwynhqvMjpQ9CToZkaF6_rfZbFzlRYeavans2e8qc6Y-E-Iai4LwqMuemNQ_uRf63T0Ec8ljGaPGsVDQz7bB742VPXhN4wFTeF
class Subject
{
public:
    /// @brief Destructeur du Subject
    virtual ~Subject() {}
    /// @brief Permet d'être suivit par un Observer
    /// @param observer {Observer} Observer de ce Subject
    void attach(Observer *observer) { vObserver.emplace_back(observer); }
    /// @brief Ne plus être suivit par l'Observer
    /// @param id {int} Identifiant de l'Observer à quitter
    void detach(const int id)
    {
        for (auto it = vObserver.begin(); it != vObserver.end(); ++it)
        {
            if ((*it)->getId() == id)
            {
                vObserver.erase(it);
            }
        }
    }
    /// @brief Prévient les Observers associés d'un changement
    void notify()
    {
        for (auto observer : vObserver)
        {
            observer->update(this);
        }
    }
    /// @brief Retourne l'state du Subject
    /// @return State {int}
    virtual int getState() = 0;
    /// @brief Modifie l'state du Subject
    /// @param state {int} État à affecter
    virtual void setState(const int state) = 0;
    /// @brief Renvoit une description de state du Subject
    /// @return Verbe pour le state {std::string}
    std::string verbState()
    {
        int stateTmp = getState();
        switch (stateTmp)
        {
        case 0:
            return "en date";
        case 1:
            return "expiré";
        }
        return "invalide";
    }
    /// @brief Modifie l'subject_id du Subject
    /// @param id {int} Identifiant à affecter
    void setId(int id) { subject_id = id; };
    /// @brief Retourne l'identifiant du Subject
    /// @return subject_id {int}
    int getId() { return subject_id; };

private:
    /// @brief Identifiant du Subject
    int subject_id;
    /// @brief Observers suivant ce Subject
    std::vector<Observer *> vObserver;
};
/// @brief Sous-Component Bouquet, Subject de Flower_Shop (Observer-Composite)
/// @see https://www.plantuml.com/plantuml/uml/PL3BJiCm4BpdAtmCeFu1GeN24Gc9tYtNteO5nnlMwoWIWc_7jaBhYfjtPZGFRwCObZJwpdeJetgWz9b0lhgDmY0gfiCxM7aL8v2XER-9RzMEnea2PC6rkbCJuvnvRT_GEuQGXKTFHfGbEBumMjZZ27jwDX-WCtaWyWgM2Ta8KgZcUWsKHdcZVjOw_LK-2Zs0L7a5PaAduXzIwvRNYJBEzKrJUo8OHfhX7zVS9MXNvlGfH1m2k1gFRYd2jbKrr1e3YjPdn58G9dy_N5RLvttzvTp6Ys7YwhLPlOotJylqM7UtOFtR37rtMmWkZVuN
class Bouquet : public Subject, public Component
{
public:
    /// @brief Desctructeur de Bouquet
    ~Bouquet() {}
    /// @brief Retourne l'état du Bouquet
    /// @return subjectState {int}
    int getState() { return subjectState; };
    /// @brief Modifie l'subjectState du Subject;
    /// @param state {int} État à affecter
    void setState(int state) { subjectState = state; };
    /// @brief Ajoute un Component au Composite + met à jour les infos du Bouquet (méthode __init__() )
    /// @param c {Component} Component à ajouter
    void add(Component *c)
    {
        private_children.push_back(c);
        __init__();
    }
    /// @brief Retire un Component du Composite + met à jour les infos du Bouquet (méthode __init__() )
    /// @param c {Component} Component à retirer
    void remove(Component *c)
    {
        for (auto iter = private_children.begin(); iter != private_children.end(); ++iter)
        {
            if (*iter == c)
            {
                private_children.erase(iter);
            }
        }
        __init__();
    }
    /// @brief Retourne un Component appartenant au Composite
    /// @param idx {uint} Index du Component à lire dans private_children
    /// @return Component en question {Component}
    Component *getChild(unsigned int idx)
    {
        return idx < private_children.size() ? private_children[idx] : nullptr;
    }

    /// @brief Constructeur d'un Bouquet : \n - Assigne l'expirationState_ "en date" \n - Assigne le coefPriceTimeToMake = .05 \n - Assigne l'm_age à 0
    Bouquet()
    {
        expirationState_ = false;
        coefPriceTimeToMake_ = 0.05;
        m_age = 0;
        std::cout << "Constructor Composite" << std::endl;
    }
    /// @brief Calcule les infos élémentaires d'un Bouquet (m_price, m_lifetime)
    void __init__()
    {
        calcPrice();
        calcExpDate();
    }
    /// @brief Viellissement de (s) Flower (s) du Bouquet selon la methode " age() " de la classe " Flower "
    void controlAge()
    {
        age();
        for (unsigned int i = 0; i < private_children.size(); ++i)
        {
            private_children[i]->age();
        }
    }
    /// @brief Change le timeToMake du Bouquet
    /// @param timeToMake {int} timeToMake du Bouquet
    void set_timeToMake(int timeToMake) { timeToMake_ = timeToMake; };
    /// @brief Présente réccursivement le Bouquet
    void __repr__()
    {
        Component *f = getChild(0);
        cout << "-Bouquet " << get_name().c_str() << " (id:" << public_id << ")"
             << " contiens:" << endl;
        cout << "- Prix du Bouquet : " << get_price() << endl;
        cout << "- timeToMake du Bouquet : " << timeToMake_ << endl;
        cout << "- Expiration du Bouquet : " << get_lifetime() << " (" << /* stateName */ verbState() << ")" << endl;
        cout << " ___Composition___" << endl;
        // Réccursion
        for (auto &&o : private_children)
            o->__repr__();
    }

private:
    /// @brief Détermine la lifetime du Bouquet à partir des lifetime (s) des Flowers
    /// @tparam {private}
    /// \todo Raise exception si lifeRemainTmp est négative
    void calcExpDate()
    {
        int expiTmp = INT_MAX;
        for (unsigned int i = 0; i < private_children.size(); ++i)
        {
            int lifeRemainTmp = private_children[i]->get_lifetime() - private_children[i]->get_age();
            if (lifeRemainTmp < expiTmp)
                expiTmp = lifeRemainTmp;
        }
        set_lifetime(expiTmp);
    }
    /// @brief Détermine le m_price d'un Bouquet à partir du m_price des Flower (s) le compsant et de son timeToMake
    /// @tparam {private}
    void calcPrice()
    {
        float totalPriceTmp = 0;
        for (unsigned int i = 0; i < private_children.size(); ++i)
        {
            totalPriceTmp += private_children[i]->get_price();
        }
        set_price(totalPriceTmp + timeToMake_ * coefPriceTimeToMake_);
    }
    /// @brief État du Bouquet
    int subjectState;
    /// @brief Components du Composite
    vector<Component *> private_children;
    /// @brief Coéfficient de pondération du m_price d'un Bouquet par son timeToMake
    float coefPriceTimeToMake_;
    /// @brief Le Bouquet est-t-il expiré (initialement false)
    bool expirationState_;
    /// @brief timeToMake_ {int} timeToMake du Bouquet
    int timeToMake_;
};
/// @brief Classe de gestion du fonctionnement des Flower (s)/ Bouquet (Observer-Singleton)
/// @see https://godbolt.org/z/5916Mc6Ez
/// @see https://www.plantuml.com/plantuml/uml/ZLAnJiCm5Dpp5Pwgf51bhoYgEY1r9IkIvThNrDIrW_rIG0Y-7QU696ehmURStNivttaPI7Xg3oQJHeJ07enxXUVLpZLFjYppIjlQW9mjol8Zcp5jYRbDW3_2LoG84Jj2alDtRENQbnR4xjacdGA_oWPd51yaQQceqHstnWbYqc5RHTK9YWv9ox6pRCfQg-CurpQoLYAx6VEvT14V8snIB1GCQAHCE7CDl23d5tzCVOr_K4JWwBHYSWUvxqCwuTrjQj1Q3QgsKOAGL-tc6PBODAH3pmlL1vB_vZH9m20ACEP2TIuw2B_d8d2yDTf3NTsMxXb8pUUNvTIWlfkyIDh_p7IbhYxcagcOy9RBTsamHCAvH-Cvxv3h5Qz_kesAsPZgljEE6XPUoyUuA3zpDRp1s-Gwa8yjiSOZ5DbdjeHLyTL_0m00
class Flower_Shop : public Observer
{
public:
    /// @brief Supprime la définition du constructeur de copie pour la classe Flower_Shop. On ne peut pas créer une copie d'un objet de cette classe en utilisant le constructeur de copie par défaut. Empêche la duplication d'objet de cette classe pour s'assurer qu'il y a un seul et unique objet de cette classe dans l'application.
    Flower_Shop(const Flower_Shop &) = delete;
    /// @brief  Définit une surcharge de l'opérateur d'affectation pour la classe Flower_Shop, marquée comme "supprimée". Elle ne peut pas être utilisée et empêche l'utilisation de l'opérateur d'affectation pour cette classe.
    /// @param  Flower_Shop Non modifiable
    /// @return None
    Flower_Shop &operator=(const Flower_Shop &) = delete;
    /// @brief Déstructeur de Flower_Shop
    ~Flower_Shop() {}
    /// @brief Créer une instance du sinleton " Flower_Shop "
    /// @return unique_instance {Flower_Shop}
    static Flower_Shop *Instance()
    {
        if (!unique_instance)
        {
            unique_instance = new Flower_Shop();
        }
        else
        {
            std::cout << "constructor : Unique Singleton already created" << std::endl;
        }
        return unique_instance;
    }
    /// @brief Vérifie que l'instance est unique
    void checkSingleton()
    {
        std::cout << "checkSingleton" << std::endl;
        if (!unique_instance)
        {
            std::cout << "checkSingleton : Unique Singleton not created" << std::endl;
        }
        else
        {
            std::cout << "checkSingleton : Unique Singleton already created" << std::endl;
        }
    }
    /// @brief Renvoit l'identifiant de l'Observer
    /// @return p_id {int}
    int getId() { return p_id; /*protected*/ }
    /// @param subject {Subject} Subject qui est mis à jour
    void update(Subject *subject);
    /// @brief Ajoute un Bouquet au Flower_Shop, (ajoute un Bouquet au vecteur des Bouquet (s) en vente (bouquets_))
    /// @param Bouquet {Bouquet} Bouquet à ajouter au Flower_Shop
    void add_bouquet(Bouquet &bouquet) { bouquets_.push_back(bouquet); };

    /// @brief Vente d'un Bouquet par le Flower_Shop (ajoute le Bouquet au vecteur des Bouquet (s) vendus (sold_bouquets_) et le supprime des Bouquet (s) en vente)
    /// @param bouquet {Bouquet} Bouquet à vendre
    void sell_bouquet(Bouquet bouquet)
    {
        int id = bouquet.get_id();
        vector<Bouquet> bouquetsLocal = get_bouquets();
        sold_bouquets_.push_back(bouquet);
        bouquets_.erase(remove_if(bouquetsLocal.begin(), bouquetsLocal.end(), [&id](Bouquet &b)
                                  { return b.get_id() == id; }),
                        bouquetsLocal.end());
    }
    /// @brief Fin de la m_lifetime du Bouquet
    /// @param bouquet {Bouquet} Bouquet arrivé â expiration
    /// \todo Cette méthode dans component pour expiration récursive
    void mark_as_expired(Bouquet &bouquet)
    {
        float soldePrice = bouquet.get_price() * coefSolde_;
        bouquet.set_price(soldePrice); // Mettre en solde à (50%)
        bouquet.setState(1);           // État expiré
        bouquet.notify();
    }
    /// @brief Retourne les Bouquets en vente au Flower_Shops
    /// @return bouquets {vector<Bouquet>}
    const std::vector<Bouquet> get_bouquets() const { return bouquets_; };
    /// @brief Retourne les Bouquet vendus par le Flower_Shops
    /// @return sold_bouquet {vector<Bouquet>}
    const std::vector<Bouquet> get_soldBouquets() const { return sold_bouquets_; };
    /// @brief Fonctionnement du Flower_Shop (mark_as_expired() en consequence)
    /// @see https://www.plantuml.com/plantuml/uml/ROzDJiCm48NtFiKiOT4B88HAA_K2MLOeCiuqTR4zhd-07ebpS34ciMJP5OiaohnlvhstZKc6bAqHdhzQQIzTWeEXBmpZS2OFCi9X48gCGPKqkGXxifuSCYVvn_fEt56-PbobtRKxEkJt2rEBCbo4aBpmAHCkrmy3F6-0tq_WCPpsDsNmuN4PRruM1vxFc4QZJvYqPQbkh_xyC5ZsRQN4X1qr1yeUecuGECePuKmXmiJOMt7aUCLmI3ArPYoKg8M8B7SkBAERgb41uEZ80Nvx7Nv_LeSQLOQFKSPnrN2wRtNVtWUjE4tVjamxDZRiXF-St5qNgjPhIpjA-dJZ6VTeQKKk1JAlCpOfMUeJCrfJoBdwLrY8BT_Drlm1
    void perf_cycle()
    {
        age_++;
        for (Bouquet &bouquet : bouquets_)
        {
            // Vérification si le Bouquet doit être mark_as_expired() et soldé
            int tmpAge = bouquet.get_lifetime();
            if (tmpAge < age_)
            {
                bool isNotExpired = bouquet.getState() == 0;
                if (isNotExpired)
                    mark_as_expired(bouquet);
            }
            bouquet.controlAge();
        }
    }
    /// @brief Présente le Flower_Shop
    void __repr__()
    {
        genericRepr(get_bouquets(), "disponibles");
        genericRepr(get_soldBouquets(), "vendus");
    }

private:
    /// @brief Constructeur de Flower_Shop
    /// \warning @param age = 4 pour la démo
    /// \warning @param Observer = 1 pour la démo
    Flower_Shop() : Observer(1), age_(4) { std::cout << "Unique Singleton Constructor" << std::endl; }
    /// @brief Présente des Bouquet (s)
    /// @param bouquets {vector<Bouquet>} Bouquet (s) à présenter
    /// @param pres {std::string} Descripteur de ce (s) Bouquet (s)
    void genericRepr(vector<Bouquet> bouquets, std::string pres)
    {
        int tmpAvaLen = bouquets.size();
        if (tmpAvaLen > 0)
        {
            cout << "Nombre de bouquets"
                 << " " << pres << ": " << tmpAvaLen << "\n"
                 << endl;
            for (Bouquet &bouquet : bouquets)
            {
                bouquet.__repr__();
                cout << endl;
            }
        }
    }
    /// @brief État de l'Observer (inutile ici)
    int observerState;
    /// @brief Permet de suivre l'instance du Singleton
    static Flower_Shop *unique_instance;
    /// @brief Liste des Bouquet (s) en vente dans le Flower_Shop
    vector<Bouquet> bouquets_;
    /// @brief Liste des Bouquet (s) vendus
    vector<Bouquet> sold_bouquets_;
    /// @brief age_ du magasin
    int age_;
    /// @brief Réduction de tarif pour un Bouquet périmé
    float coefSolde_ = .5;
};
/// @brief Méthode update() de la partie Observer du Flower_Shop
/// @param subject {Subject} Subject qui est setState()
void Flower_Shop::update(Subject *subject)
{
    int subId = subject->getId();
    std::cout << "Subject(id=" << subId << ") update state to: " << subject->verbState() << std::endl;
}
/// @brief Rassemble conception et lien entre Bouquet, Flower (fabrique)
/// @see https://godbolt.org/z/zh8vjWj44
/// @see https://www.plantuml.com/plantuml/uml/LO-n3i8m34HtVuKdHDL-0a8LGpSsHXQJkfL5ce3Zme3uTm8j5Kovoyb-vpePgOs31-Sf9Mpef78T-G4bxkAObQ5J9kFPhPEfX1u33LmXI30q6VWGztJE7sylRON7W3Ts5dM3ZOztLjpYglkez9ika1pFCXLGVeScz6J-o81v6HbULDoCzT9nhhAKc5xgkO0dr1pQVEKB
class Fabrique
{
public:
    /// @brief Fabrique de Bouquet (s)
    /// @param name {string} Nom du Bouquet
    /// @param timeToMake {int} Temps de fabrication
    /// @param id {int} Identificateur
    /// @param lifetime {int} Temps de vie
    /// @param flowers {vector<Flower>} Flower (s) contenues dans le Bouquet
    /// @param bouquets {vector<Bouquet>} Sous-Bouquets du Bouquet
    /// @tparam coefPriceTimeToMake {float} Coefficient de pondération ente le m_price des Flower (s) et le timeToMake du Bouquet
    Bouquet createBouquet(string name, int timeToMake, int id, vector<Flower> &flowers, vector<Bouquet> &bouquets)
    {
        Bouquet *tmpBouquet = new Bouquet();
        tmpBouquet->set_name(name);
        tmpBouquet->set_timeToMake(timeToMake);
        tmpBouquet->set_id(id); // en pratique vérifier si il n'ya pas de doublons
        for (Flower &flower : flowers)
        {
            tmpBouquet->add(&flower);
        }
        for (Bouquet &bouquet : bouquets)
        {
            tmpBouquet->add(&bouquet);
        }
        return *tmpBouquet;
    }
    /// @brief Fabrique de Flower (s)
    /// @param name {string} Nom de la Flower
    /// @param price {float} Prix de la Flower
    /// @param lifetime {int} Durée de vie de la Flower
    /// @param age {int} Age de la Flower
    /// @param id {int} Identifiant de la Flower
    Flower createFlower(string name, float price, int lifetime, int id, int age)
    {
        Flower *tmpFlower = new Flower();
        tmpFlower->set_name(name);
        tmpFlower->set_price(price);
        tmpFlower->set_lifetime(lifetime);
        tmpFlower->set_age(age);
        tmpFlower->set_id(id);
        return *tmpFlower;
    }
};
/// @brief Témoin de l'unique instance d'un Flower_Shop
/// @see https://www.plantuml.com/plantuml/uml/LO_D3e9038Jl-nGz6GayWZ74WpTEUZGX5GfkN7QnBNemlhiiFp6UEirqvajpKMGTEcSgXo9mTE55N9vkeIyBzDWIlqqAXp0y1bAupdChojQtuB6Zp5YleBQZSoZmJjd5FwdImBkb3FQmQIObFszjZEPIAeb9ryXy_uU1YOFjgA9mjg4H6d5njNKMGwZGiwqeCH-Jaw_7nxu0
Flower_Shop *Flower_Shop::unique_instance = nullptr;
/// @brief Classe regroupant les Interface (s) de Flower_Shop, Flower et Bouquet (Facade)
/// @see https://godbolt.org/z/oWTWTaPc3
/// @see https://www.plantuml.com/plantuml/uml/TT6zJiD0303WtK_X2L6rVOCALGpTEi4OgN9Ifvn8VCNdm02yEtV4bPh-JB5ZdUrFNYSZjQ7leEae9TnGhU5Zu6-OutCSScJOA9EnPu_9DCW1XNfU80GnjD3pQzpIU_vHyh1VO2NuoOr5NU6cYr-i-8GFxN-K9bLlMyeUfXdC_P6F7fF9PC3SZ0oF6XeVsuMMoogd9SOl7NW6lwFEk-vUtk9njoN9DJs7rZU8by9AxhkyDbNLrwhsseFWorvOAd7CkRU0JeV2rSzoUGi6QvPzFkmV
class Flower_Shop_Manager : public Fabrique
{
public:
    /// @brief Fabrique de Bouquet (s)
    /// @param name {string} Nom du Bouquet
    /// @param timeToMake {int} timeToMake
    /// @param id {int} Identificateur
    /// @param flowers {vector<Flower>} Flower (s) contenues dans le Bouquet
    /// @param bouquets {vector<Bouquet>} Sous-Bouquets du Bouquet
    /// @tparam coefPriceTimeToMake {float} Coefficient de pondération entre le m_price des Flowers et le timeToMake du Bouquet
    /// @see https://www.plantuml.com/plantuml/uml/TP71JiGW48RlVGgo9ptu0XxCPjMzDJ6fzsPAnzrH2aYf-lZEB8r0rKDJ-Bz_VWPcFqS8SPbCu_bFcZpOg7P7upunzDtP-Ru52oSCEmMpEdPjevqng2CvErV6rR3XC0HwNp1166hQBSChRowGrpKyk8KB4vHrJU_Tv9r5cxZi6c3s0H4lNVAdRkvugMxL2MC_fBJvwZgZbjcg5p8CBEk0d7JuWJcRxy2VEELGjiwSJYDxViiM9in0qbOGQS9dry8RbjbYs9XXbEGHg_E55Hwon2rkLGr6Ftxv1oxAi6pEq0jA7t-NFWNI_nJw6jKFMVOgXlLPPRpLMvKgn0ZwN4uctRpFmzcZ7PV9V0C0
    Bouquet bouquet(string name, int timeToMake, vector<Flower> &flowers /*  = vector<Flower>() */, vector<Bouquet> &bouquets /*  = vector<Bouquet>() */)
    {
        int id = shop->get_bouquets().size(); // incomplet
        Bouquet tmpBouquet = createBouquet(name, timeToMake, id, flowers, bouquets);
        tmpBouquet.attach(shop);
        tmpBouquet.setId(id);
        shop->add_bouquet(tmpBouquet);
        return tmpBouquet;
    };
    /// @brief Constructeur de la classe Flower
    /// @param name {string} Nom de la Flower
    /// @param price {float} Prix de la Flower
    /// @param lifetime {int} Durée de vie de la Flower
    /// @param age {int} Age de la Flower
    /// @param id {int} Identifiant de la Flower
    Flower flower(string name, int age, int lifetime, int id, float price) { return createFlower(name, age, lifetime, id, price); };
    /// @brief Instance unique du Flower_Shop est allouée au gérant
    /// @see https://www.plantuml.com/plantuml/uml/ZLHDRzim3BthLn0OKDXj3EmSD4FHGu4UYW7BZWK4HM9IBRBaINAs8Lj_--XOJkNO-pY57u_aqoETkn25Zsrjc3GY17WG6w-_jdXaDt3lMh8YI8yYOlAA4BssEx2YnWKmRID4NUDdzoJs5EXyhHRmRE60CZf_2m_6VKCF7-1gUxB2A3iCeNGoGybkKb4QtJkZoGoecOZGU2tJMAEtI5Go4jsls679VgNNVTm4z0VqH_Rkb6ouLZHi21VIsH1JUSVYe4aROU3rZCYZ1wSLj8qYXiMwtNn16U4wz4QvUfyXkuuxZ8-geFZ09hsHhrzSmv-49QO-btqp8_Ybti_spofJRghnPgfnZv_PgzXTA4ijaxIv-kNSWuwiEfMw9DmwYeWKcr8Q6F7PR716yHoIY96PE4Y7spMXJg50OxJCYR1hQAscSgujPQr4TfFdqywp25oLAuK6unX9SN0DUa4CL_-eUiq7aDJzgSWNbFirYKmePxjuTXZa_VsWXhnGPq6AGQTXhMTGG6Ccg4jGBVoUYy3nUwCzgjbk_Jj3LClbT3d4_BoRekon_rFJBVL-KjUJ8eMtNFwG1jyauTnZupdl8lChVaox9KILfpg_xx53YrxBJzIek63rTeEBddNw51gFeJlkuUE7sv_Lg3lBR73Z72oXcbpUyE-QEas__r77gd9p6EfCAdJZxz2gjZQ_0G00
    Flower_Shop *shop = Flower_Shop::Instance();
};
/// @brief Présenation des fonctionnalités du programme
/// @return onformations sur le programme
int main()
{

    /// \test Instantiation du gestionnaire de magasin
    Flower_Shop_Manager manager;

    /// \test Plusieurs groupes de fleurs
    vector<Flower> fleurs;
    vector<Flower> fleurs1;

    /// \test Plusieurs groupes de bouquets
    vector<Bouquet> bouquets;
    vector<Bouquet> bouquets1;

    /// \test  Assemblage d'un groupe de fleurs
    std::string name[3] = {"Rose", "Tulipe", "Jonquille"};
    for (unsigned int i = 0; i < 3; ++i)
    {
        /// \test Création de fleurs
        Flower tmpFlower = manager.createFlower(name[i], 5, 5, 0, i);
        /// \test Groupement de fleurs
        fleurs.push_back(tmpFlower);
    }
    /// \test Fleur individuelle
    Flower tmpFlower = manager.createFlower("Marguerite", 5, 5, 0, 1);
    /// \test Ajout à un groupe pour le passage à la fabrique de bouquets
    fleurs1.push_back(tmpFlower);
    /// \test Création d'un bouquet avec des multiples fleurs
    Bouquet composite = manager.bouquet("principal", 5, fleurs, bouquets);
    /// \test Groupement de bouquets
    bouquets1.push_back(composite);
    /// \test Composition de bouquet + fleurs
    Bouquet composite1 = manager.bouquet("secondaire", 5, fleurs1, bouquets1);
    /// \test Vue du système à cette étape
    manager.shop->__repr__();
    /// \test Du temps passe ...
    manager.shop->perf_cycle();
    manager.shop->perf_cycle();

    int id = composite1.get_id();
    vector<Bouquet> bouquetsLocal = manager.shop->get_bouquets();
    Bouquet delBouquet = bouquetsLocal[id];

    /// \test Un bouquet est vendu
    manager.shop->sell_bouquet(delBouquet);
    /// \test État du système à ce moment
    manager.shop->__repr__();
    return 0;
};