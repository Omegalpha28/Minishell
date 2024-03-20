/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-ossan.msoili
** File description:
** my_strlen.test
*/

#include "../../header/minishell.h"
#include <criterion/criterion.h>

Test(my_strlen, basic_string_length)
{
    char str[] = "hello world";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(my_strlen, empty_string_length)
{
    char str[] = "";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(my_strlen, long_ass_text)
{
    char str[] = "Pika pika! Pikachu, Pikachu chu chu! Pika pika chu chu, Pika-chu, Pika-pi! Pikachu, Pikachu chu chu. Pikachu-chu, pika pika! Pikachu! Pika pika chu, Pikachu-pi! Pika pika chu. Pika, Pikachu chu chu. Pikachu-pi, pika pika chu! Pikachu-chu! Pika pika! Pikachu chu, Pikachu-pi. Pika pika chu, pika! Pika-chu, Pikachu chu chu chu! Pika-chu-chu, pika pika. Pikachu-chu! Pika pika chu chu, pika pika. Pika pika, Pikachu chu chu chu! Pika-pi, Pikachu-pi, pika chu chu chu. Pika-chu, pika pika chu chu. Pikachu, pika pika chu chu. Pika pika, Pikachu chu chu. Pika-chu-chu! Pika pika chu, Pikachu chu chu chu. Pika pika, Pikachu-pi. Pika-chu, Pikachu chu chu. Pika pika chu chu chu! Pika-pi, Pikachu chu chu chu. Pika pika chu, Pikachu-pi. Pika-chu chu chu! Pika pika chu chu, Pikachu-pi. Pika-chu, pika pika chu. Pika pika, Pikachu chu chu chu! Pika pika chu, Pikachu-pi. Pika pika chu chu. Pikachu-chu chu! Pika pika chu chu chu, pika pika. Pika pika, Pikachu-pi. Pika-chu, Pikachu chu chu. Pika pika chu chu chu! Pika-chu-chu, Pikachu-pi. Pika pika chu chu. Pikachu-chu chu chu! Pika pika chu, Pikachu-pi. Pika-chu, pika pika chu chu. Pika pika, Pikachu chu chu chu! Pika-chu-chu, pika pika. Pika pika chu chu, Pikachu chu chu chu. Pika-chu, pika pika chu chu chu! Pika-chu, Pikachu-pi. Pika pika chu chu, Pikachu chu chu. Pika pika, Pikachu chu chu chu! Pika-chu-chu, pika pika. Pika pika chu chu chu! Pika-chu, Pikachu chu chu. Pika pika chu chu chu! Pika pika chu, Pikachu-pi. Pika-chu chu chu! Pika pika chu chu chu, Pikachu chu chu. Pika pika, Pikachu-pi. Pika-chu, pika pika chu chu. Pika pika chu chu chu! Pika pika, Pikachu chu chu. Pika-chu-chu! Pika pika chu, Pikachu chu chu chu. Pika pika, Pikachu-pi. Pika-chu, Pikachu chu chu. Pika pika chu chu chu! Pika-chu-chu, Pikachu-pi. Pika pika chu chu. Pikachu-chu chu chu! Pika pika chu, Pikachu-pi. Pika-chu, pika pika chu chu. Pika pika, Pikachu chu chu chu! Pika-chu-chu, pika pika. Pika pika chu chu chu, pika pika. Pika pika, Pikachu-pi. Pika-chu, Pikachu chu chu. Pika pika chu chu chu! Pika-chu-chu, Pikachu-pi. Pika pika chu chu. Pikachu-chu chu chu! Pika pika chu, Pikachu-pi. Pika-chu, pika pika chu chu. Pika pika, Pikachu chu chu chu! Pika-chu-chu, pika pika. Pika pika chu chu chu! Pika-chu, Pikachu chu chu. Pika pika chu chu chu! Pika pika chu, Pikachu-pi. Pika-chu chu chu! Pika pika chu chu chu, Pikachu chu chu. Pika pika, Pikachu-pi. Pika-chu, pika pika chu chu. Pika pika chu chu chu! Pika-chu-chu, Pikachu-pi. Pika pika chu chu. Pikachu-chu chu chu! Pika pika chu, Pikachu-pi. Pika-chu, pika pika chu chu. Pika pika, Pikachu chu chu chu! Pika-chu-chu, pika pika. Pika pika chu chu chu! Pika-chu, Pikachu chu chu. Pika pika chu chu Pikachu, Pikachu chu chu! Pikachu and Digimon are like Bulbasaur and Charmander—both cute and powerful but different in their own ways. Pikachu's journey revolves around trainers catching Pokémon, training them, and battling alongside their adorable partners. On the other paw, Digimon explores a digital world where digital monsters evolve and fight to save their digital realm. While Pikachu's adventures are bright and playful, Digimon's are often more intense and serious, with darker themes and epic battles. Pikachu's world is filled with friendship, teamwork, and Poké Balls, while Digimon's digital realm is a mix of technology and fantasy. Pikachu's games are about collecting badges and becoming a Pokémon Champion, while Digimon's games focus on evolving and battling digital monsters. Both Pikachu and Digimon have captured the hearts of fans worldwide, each with its own electrifying charm and unique appeal. Pika pika!";

    cr_assert(my_strlen(str) == strlen(str));
}
