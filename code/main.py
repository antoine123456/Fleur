from datetime import datetime,timedelta
class Flower:
    def __init__(self, name: str, age: int, lifetime: int):
        self.name = name
        self.age = age
        self.lifetime = lifetime

    def age(self):
        self.age += 1

    def __repr__(self):
        return "Nom : {}\nAge : {}\nDurée de vie : {}".format (self.name,self.age,self.lifetime)


class Bouquet:
    def __init__(self, flowers, price: float, time_to_make: int):
        self.flowers = flowers
        self.price = price
        self.time_to_make = time_to_make
        self.expiration_date = max(list(map(lambda this : this.lifetime,bouquet.flowers)))

    def age(self):
        for flower in self.flowers:
            flower.age()

    def __repr__(self):
        print("Nombre de fleurs : {}\nPrix : {}\nTemps de fabrication : {}\nDate d'expiration : {}\nComposition:\n".format(len(self.flowers),self.price,self.time_to_make,self.expiration_date))
        for flower in self.flowers:
            print(flower)
        return ""

class FlowerShop:
    def __init__(self):
        self.bouquets = []
        self.sold_bouquets = []

    def add_bouquet(self, bouquet: Bouquet):
        self.bouquets.append(bouquet)

    def sell_bouquet(self, bouquet: Bouquet):
        self.bouquets.remove(bouquet)

    def mark_as_expired(self, bouquet: Bouquet):
        self.bouquets.remove(bouquet)
        bouquet.price *= 0.5  # mettre en solde à 50%
        self.bouquets.append(bouquet)

    def __repr__(self):
        nbBouquets=len(self.bouquets)
        if(nbBouquets>0):
            print("Nombre de bouquets disponibles : {}\nBouquets disponibles :\n".format(nbBouquets))
            for bouquet in self.bouquets:
                print(bouquet)

        nbSoldBouquets=len(self.sold_bouquets)
        if(nbSoldBouquets>0):
            print("Nombre de bouquets vendus : {}\nBouquets vendus :\n".format(nbSoldBouquets))
            for bouquet in self.sold_bouquets:
                print(bouquet)
        return ""

rose=Flower("Rose",0,5)

bouquet=Bouquet([rose],10,30)

# # Création d'une rose et d'un bouquet de roses
# rose = Flower("Rose", 0)

# print(rose)

# bouquet = Bouquet([rose], 10, 30, datetime.now()+timedelta(days=3))

# print(bouquet)

# # Création d'un magasin de fleurs
# flower_shop = FlowerShop()

# # Ajout du bouquet de roses au magasin
# flower_shop.add_bouquet(bouquet)

# # Passage de la date de péremption du bouquet à demain
# bouquet.expiration_date = datetime.now() + timedelta(days=1)

# # Vérification si le bouquet doit être mis en solde
# if bouquet.expiration_date - datetime.now() < timedelta(days=1):
#     flower_shop.mark_as_expired(bouquet)

# print(flower_shop)

# # Vente du bouquet
# flower_shop.sell_bouquet(bouquet)

# print(flower_shop)