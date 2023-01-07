Un magasin de fleurs souhaite s'équipe d'un gestionnaire de bouquet. 

Il s'agit de pouvoir agréger des fleurs différentes ou identiques (on peut avoir 2 roses, et des fleurs différentes) dans un bouquet.

Celui-ci aura un prix en fonction des fleurs qui sont associées et du temps de réalisation du bouquet.

 Un bouquet aura une date de péremption qui sera déterminé par la fleur la plus ancienne.
 
 On a donc un verbe "vieillissement" qui est envoyé à toutes les fleurs - pour incrémenter l'âge de celles-ci. 
 
 Le ou les bouquets sont exposés dans un magasin - lorsqu'un bouquet arrive à une date proche de la date de péremption, il est soldé. 
 
 Lorsqu'un bouquet est vendu il n'est plus disponible dans le magasin.

 "tasks": [
        {
            "taskName": "script",
            "isBuildCommand": true,
            "type": "shell",
            "group": {
                "kind": "test",
                "isDefault": true
            },
            "command": "\"g++ main.cpp && ./a.out",
            "options": {
                "shell": {
                    "executable": "C:\\Users\\antoine\\AppData\\Local\\Microsoft\\WindowsApps\\KaliLinux.54290C8133FEE_ey8k8hqnwqnmg\\kali.exe",
                    "args": [
                        "-c"
                    ]
                }
            }
        }
    ]
    {
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "command": "python",
    "isShellCommand": true,
    "showOutput": "never",
    "suppressTaskName": true,
    "tasks": [
        {
            "taskName": "script",
            "args": [
                "./code/main.py"
            ],
            "isBuildCommand": true,
            "showOutput": "never"
        }
    ]
}