# ChainesDeCaracteres

#### Projet Chaines de Caracteres, cf.Cahier des charges

<br/>

**Méthode canary :**<br/>
>dans ./.bashrc ajouter :<br/>
>alias gccCanary='gcc -std=c89 -pedantic -Wall -Wextra -m32 -fstack-protector '
<br/>
<br/>

**Télécharger et installer Cunit :**<br/>
>[télécharger les sources](https://sourceforge.net/projects/cunit/files/)<br/><br/>
><ins> Ouvrir un cmd et taper (installe dans le dossier $HOME/local ) : </ins> <br/>
>- $ tar xjvf CUnit-2.1.2-src.tar.bz2<br/>
>- $ cd CUnit-2.1-2<br/>
>- $ ./configure --prefix=$HOME/local<br/>
>- $ make<br/>
>- $ make install <br/>
>
>Dans ./.bashrc ajouter :<br/>
>alias gcCunti='gcc -std=c89 -pedantic -Wall -Wextra -I${HOME}/local/include'

**Pour plus d'informations sur Cunit voir ces 2 liens :** <br/> 
-[pour l'installation](https://sites.uclouvain.be/SystInfo/notes/Outils/html/cunit.html)
-[pour la programmation](https://sites.uclouvain.be/SystInfo/notes/Outils/html/cunit.html)
