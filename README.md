# 🌊 OceanDepth 🤿🐙

Projet d’exploration sous-marine en **langage C**.  
Le joueur incarne un plongeur affrontant des créatures marines tout en gérant ses ressources vitales (oxygène, vie, fatigue).
- Génération aléatoire de créatures selon la profondeur  
- Attaque du plongeur avec gestion de l'oxygène et de la fatigue  
- Riposte des créatures (à venir dans la Partie 3)  
- Système de récompenses, inventaire et carte marine prévus dans les prochaines étapes  

---

## ⚙️ Compilation & exécution

### 🪟 Sous **Windows / VS Code (MinGW32)**
```powershell
mingw32-make clean
mingw32-make
mingw32-make run
```

> 💡 Nécessite MinGW ou MSYS2 avec la commande `mingw32-make` disponible dans le PATH.

### 🧰 Sous **CLion**, **Linux** ou **macOS**
```bash
make
./oceandepths
```

---

## 🧰 Prérequis

- Compilateur **GCC** compatible C99  
- Environnement **MinGW** ou **MSYS2** sous Windows  
- (Optionnel) `make` ou `mingw32-make` pour automatiser la compilation  

---
