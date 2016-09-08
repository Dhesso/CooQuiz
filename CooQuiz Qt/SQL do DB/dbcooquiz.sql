-- phpMyAdmin SQL Dump
-- version 4.5.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 08-Set-2016 às 23:28
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
(2, 'ciencia da computacao', 'programacao III', '90', 'ponteiros', 'moderado', '<h3><p>O que as linhas abaixo fazem? Antes da chamada do método misterio(&i,&j), temos a seguinte linha de comando:</h4></p> <h5><p>"int i=6, j=10;</p>\n\n<p>void misterio(int *p, int *q){</p>\n\n <p> int temp;</p>\n\n  <p>temp = *p;</p>\n\n  <p>*p = *q;</p>\n\n  <p>*q = temp; }"</p>\n</h5>', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para i e q apontando para j.', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para j e q apontando para i.', 'nao faz nada.', 'soma i e j.', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para i e q apontando para j.');

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
(1, 'jeferson', 'dhesso', '12345678', 'unifap', 'bcc', 'ADM', 0, NULL);

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
  MODIFY `ID` smallint(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
