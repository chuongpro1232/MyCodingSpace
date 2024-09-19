
const express = require('express');
const router = express.Router();
const Movie = require('../models/Movie');

// Home Page - View Movies
router.get('/', async (req, res) => {
  const movies = await Movie.find({});
  res.render('index', { movies });
});

// Add Movie Page
router.get('/add-movie', (req, res) => {
  if (!req.session.user) return res.redirect('/auth/login');
  res.render('add-movie');
});

// Add Movie Logic
router.post('/add-movie', async (req, res) => {
  const { title, releaseYear, genre } = req.body;
  try {
    await Movie.create({ title, releaseYear, genre });
    req.flash('success_msg', 'Movie added successfully!');
    res.redirect('/');
  } catch (error) {
    res.render('add-movie', { error: error.message });
  }
});

module.exports = router;
            