-- phpMyAdmin SQL Dump
-- version 4.5.2
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 26-Jul-2016 às 07:43
-- Versão do servidor: 5.7.9
-- PHP Version: 5.6.16

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

DROP TABLE IF EXISTS `perguntas`;
CREATE TABLE IF NOT EXISTS `perguntas` (
  `ID` smallint(5) UNSIGNED NOT NULL AUTO_INCREMENT,
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
  `resposta` text NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ID` (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `perguntas`
--

INSERT INTO `perguntas` (`ID`, `curso`, `disciplina`, `ch`, `tema`, `dificuldade`, `cabecalho`, `alternativa1`, `alternativa2`, `alternativa3`, `alternativa4`, `resposta`) VALUES
(1, '', '', '0', '', 'iniciante', 'qual das alternativas e a?', 'a', 'b', 'c', 'd', 'a'),
(2, 'ciencia da computacao', 'programacao III', '90', 'ponteiros', 'moderado', 'O que as linhas abaixo fazem? Antes da chamada do método misterio(&i,&j), temos a seguinte linha de comando: "int i=6, j=10;"\r\n\r\n"void misterio(int *p, int *q){\r\n\r\n  int temp;\r\n\r\n  temp = *p;\r\n\r\n  *p = *q;\r\n\r\n  *q = temp;\r\n\r\n}"', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para i e q apontando para j.', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para j e q apontando para i.', 'nao faz nada.', 'soma i e j.', 'muda os valores da variavel i para a varial j usando os ponteiros p apontando para i e q apontando para j.');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
