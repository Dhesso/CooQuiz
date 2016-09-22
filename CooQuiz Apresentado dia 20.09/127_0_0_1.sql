-- phpMyAdmin SQL Dump
-- version 4.5.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 22-Set-2016 às 01:46
-- Versão do servidor: 5.7.11
-- PHP Version: 5.6.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dbcooquiz`
--
CREATE DATABASE IF NOT EXISTS `dbcooquiz` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `dbcooquiz`;

-- --------------------------------------------------------

--
-- Estrutura da tabela `perguntas`
--

CREATE TABLE `perguntas` (
  `ID` smallint(5) UNSIGNED NOT NULL,
  `curso` varchar(30) NOT NULL,
  `disciplina` varchar(30) NOT NULL,
  `ch` decimal(3,0) UNSIGNED NOT NULL,
  `tema` varchar(30) NOT NULL,
  `dificuldade` enum('iniciante','moderado','avancado') NOT NULL,
  `cabecalho` text NOT NULL,
  `alternativa1` text NOT NULL,
  `alternativa2` text NOT NULL,
  `alternativa3` text NOT NULL,
  `alternativa4` text NOT NULL,
  `resposta` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `perguntas`
--

INSERT INTO `perguntas` (`ID`, `curso`, `disciplina`, `ch`, `tema`, `dificuldade`, `cabecalho`, `alternativa1`, `alternativa2`, `alternativa3`, `alternativa4`, `resposta`) VALUES
(1, 'eliza', '', '0', '', 'iniciante', '<h3>qual das alternativas e a?</h3>', 'a', 'b', 'c', 'd', 'a'),
(2, 'ciencia da computacao', 'programacao III', '90', 'ponteiros', 'moderado', '<h3><p>O que as linhas abaixo fazem? Antes da chamada do método misterio(&i,&j), temos a seguinte linha de comando:</h4></p> <h5><p>"int i=6, j=10;</p>\n\n<p>void misterio(int *p, int *q){</p>\n\n <p> int temp;</p>\n\n  <p>temp = *p;</p>\n\n  <p>*p = *q;</p>\n\n  <p>*q = temp; }"</p>\n</h5>', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para i e q apontando para j.', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para j e q apontando para i.', 'nao faz nada.', 'soma i e j.', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para i e q apontando para j.'),
(3, 'ciencia da computacao', 'programacao III', '10', 'ponteiros', 'moderado', 'teste', 'a', 'b', 'c', 'd', 'a'),
(4, 'silinhas', '', '10', '', 'moderado', '', '', '', '', '', ''),
(5, 'ciencia da computacao', 'programacao III', '90', 'funções', 'moderado', 'Todas as seguintes afirmativas são verdadeiras sobre funções, exceto:\r\n', 'Uma chamada de função deve especificar o nome e argumentos da função.', 'Elas definem tarefas específicas que podem ser usadas em muitos pontos de um programa.', 'A definição de uma função geralmente é visivel para outras funções.', 'A implementação de uma função é escondida do chamador.', 'É um erro de compilação declarar funções no corpo de outra função.'),
(6, 'ciencia da computacao', 'programacao III', '90', 'funções', 'moderado', 'Na expressão “n = x + rand() % y;”:', 'é o valor de escala.', 'y é o valor de deslocamento.', 'ambos (a) e (b).', 'A implementação de uma função é escondida do chamador.', 'x é o valor de escala.'),
(7, 'ciencia da computacao', 'programacao III', '90', 'funções', 'moderado', 'A passagem de parâmetros por referência pode alcançar a segurança da passaagem de parâmetros por valor quando:', 'Um ponteiro para o argumento é usado.', 'Um argumento longo é passado, a fim de melhorar o desempenho.', 'O valor a ser transmitido é pequeno.', 'O qualificador const é usado.', 'Um ponteiro desreferenciado é usado.'),
(8, 'ciencia da computacao', 'programacao III', '90', 'funções', 'moderado', 'Retornar referências a membros de dados privados não constantes:', 'É apenas perigoso se o operador de resolução de escopo binário (::) for usado no protótipo da função.', 'Permite que membros de dados sejam modificados, assim, o encapsulamento é quebrado.', 'Resulta em um erro do compilador.', 'Permite que as funções privadas sejam modificadas.', 'Resulta em ganho de desempenho e de segurança.'),
(9, 'ciencia da computacao', 'programacao III', '90', '', 'moderado', 'Qual das seguintes afirmações não produzirá um erro de sintaxe?', 'Declarar um objeto sendo const.', 'Invocar uma função membro não-const a partir de um objeto const.', 'Definindo de uma função membro const que modifica um membro de dados do objeto.', 'Declarar o construtor para ser const.', 'Declarar um destrutor para ser void.'),
(10, 'ciencia da computacao', 'programacao III', '90', '', 'moderado', 'Assuma que t é um objeto da classe Teste, que tem as funções a(), b(), c() e d(). Se as funções a(), b() e c() retornam referências para um objeto da classe Teste (usando o ponteiro this desreferenciado) e a função d() é declarada como void, qual das seguintes afirmações não produzirá um erro de sintaxe:', 't.a().t.d();', 'a().b().t;', 't.d().c();', 't.a().b().d();', 't->a()->d()->b();'),
(11, 'Ciência da Computação', 'Arquitetura de Computadores', '90', '', 'moderado', 'Em 1946, o matemático Von Neumann idealizou o modelo sobre o qual os computadores atuais baseiam-se. Assim, este modelo é composto pelos componentes:', 'Unidade de entrada e saída e unidade de memória', 'Unidade lógica e aritmética, unidade entrada e saída e unidade de memória.', 'Unidade de memória, unidade de controle, unidade de entrada e unidade de saída.', 'Unidade de memória, unidade lógica e aritmética, unidade de entrada, unidade de saída e unidade de controle.', 'Unidade lógica e aritmética e unidade de memória.'),
(12, 'Ciência da Computação', 'Arquitetura de Computadores', '90', '', 'moderado', 'Sobre as aquiteturas de hardware CISC e RISC, assinale a alternativa correta:', 'As aquiteturas CISC possuem um conjunto simples de instruções.', 'Atualmente, os fabricantes de computadores tem adotado exclusivamente a arquitetura RISC para o desenvolvimento de chips para processdores, dado o melhor desempenho dessa arquitetura CISC.', 'Na arquitetura CISC, não há microprogramação para interpretar as instruções.', 'As arquiteturas RISC possuem instruções com estrutura mais heterogênea.', 'Na arquitetura CISC, as instruções possuem tamanho variável.');

-- --------------------------------------------------------

--
-- Estrutura da tabela `usuarios`
--

CREATE TABLE `usuarios` (
  `id` int(11) NOT NULL,
  `nome` varchar(300) NOT NULL,
  `loginName` varchar(100) NOT NULL,
  `senha` char(8) NOT NULL,
  `instituicao` varchar(300) DEFAULT NULL,
  `curso` varchar(300) DEFAULT NULL,
  `tipo` varchar(8) NOT NULL,
  `pontuacao` int(10) UNSIGNED DEFAULT NULL,
  `rank` int(10) UNSIGNED DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `usuarios`
--

INSERT INTO `usuarios` (`id`, `nome`, `loginName`, `senha`, `instituicao`, `curso`, `tipo`, `pontuacao`, `rank`) VALUES
(1, 'jeferson', 'dhesso', '12345678', 'unifap', 'bcc', 'ADM', 0, NULL),
(2, 'eliza', 'eliza', '123', 'unifap', 'bcc', 'ADM', 0, 2);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `perguntas`
--
ALTER TABLE `perguntas`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `ID` (`ID`);

--
-- Indexes for table `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `nome` (`nome`),
  ADD UNIQUE KEY `loginName` (`loginName`),
  ADD UNIQUE KEY `loginName_2` (`loginName`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `perguntas`
--
ALTER TABLE `perguntas`
  MODIFY `ID` smallint(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;
--
-- AUTO_INCREMENT for table `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
